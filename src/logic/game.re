open Helpers
Random.self_init()

type gameState = {
   score: int,
   board: list(list(option(int))),
   isGameOver: bool
 }
let rec numberJoiner = row =>
  switch (row) {
    | [] => row
    | [Some(first), Some(second), ...rest] when first == second => List.append([Some(first + second), ...numberJoiner(rest)], [None])
    | [Some(first), Some(second), ...rest] => [Some(first), ...numberJoiner([Some(second), ...rest])]
    | [None, ...rest] => List.append(numberJoiner(rest), [None])
    | [Some(num), None] => [Some(num), None]
    | [Some(num), None, ...rest] when onlyNones(rest) => [Some(num), None, ...rest]
    | [Some(num), None, ...rest] => numberJoiner(List.append([Some(num), ...rest], [None]))
    | [Some(_)] as x => x
  }

let isNone = i => i == None
let moveRowRight = row => {
  let row = List.rev(numberJoiner(row))
  let nones = List.filter(isNone, row)
  let nums = List.rev(List.filter(i => !isNone(i), row))

  List.append(nones, nums);
}
let moveRowLeft = row => numberJoiner(row)

let rec transpose = (board) =>
  switch (board) {
    | [] => []
    | [[], ..._] => []
    | board => [List.map(List.hd, board), ...transpose(List.map(List.tl, board))]
  }

let moveLeft = board => List.map(moveRowLeft, board);

let moveRight = board => {
  List.map(moveRowRight, board);
};

let moveUp = board =>
  transpose(board)
    |> moveLeft
    |> transpose

let moveDown = board =>
  transpose(board)
    |> moveRight
    |> transpose

let hasNones = board =>
  List.fold_left((acc, i) => List.append(acc, i), [], board)
    |> List.exists(i => i == None)

let possibleMoves = board =>
  List.exists(hasNones, [
    moveRight(board),
    moveLeft(board),
    moveUp(board),
    moveDown(board)
  ])

let isGameOver = board => !possibleMoves(board)

let rec findNewBlocks = (beforeMove, afterMove) => {
  switch (beforeMove) {
    | [] => afterMove
    | [a, ...rest] => findNewBlocks(rest, removeN(afterMove, a))
  }
}

let moveScore = (beforeMove, afterMove) => {
  findNewBlocks(List.flatten(beforeMove), List.flatten(afterMove))
  |> optionSum
}


let newBlock = () => Some((Random.int(2) + 1) * 2);
let toCoordinate = (board, index) => {
  let rows = List.length(board)
  let rowLength = List.nth(board, 0) |> List.length

  let column = mod_float(float_of_int(index), float_of_int(List.length(board)));
  let row = int_of_float(floor(float_of_int((index / rowLength))));

  (column, row)
}

let addBlock = (board) => {
  let noneCoordinates = List.flatten(board)
    |> List.mapi((index, i) => {
      switch (i) {
        | None => Some((toCoordinate(board, index)))
        | Some(_) => None
      }
    }) |> List.filter(i => i != None);

    if (List.length(noneCoordinates) == 0) {
      board
    } else {
      let newBlockIndex = Random.int(List.length(noneCoordinates));
      switch (List.nth(noneCoordinates, newBlockIndex)) {
        | Some((x, y)) => {
          let row = List.nth(board, y);
          let newRow = replace(row, int_of_float(x), newBlock());
          replace(board, y, newRow);
        }
        | None => {
          board
        }
      }
    }
}

let newGame = () =>
  [
    [None, None, None, None],
    [None, None, None, None],
    [None, None, None, None],
    [None, None, None, None]
  ] |> addBlock
    |> addBlock


type action =
  | MoveRight
  | MoveLeft
  | MoveUp
  | MoveDown
  | Restart;


let getNextBoard = (state, action) => switch(action) {
  | MoveRight => moveRight(state.board)
  | MoveLeft => moveLeft(state.board)
  | MoveUp => moveUp(state.board)
  | MoveDown => moveDown(state.board)
  | Restart => state.board

}

let getInitialState = () => ({
  score: 0,
  board: newGame(),
  isGameOver: false
})

let play = (action, state) => {
  if (action == Restart) {
    {
      score: 0,
      board: newGame(),
      isGameOver: false
    }
  } else {
    let nextBoard = getNextBoard(state, action);
    let score = moveScore(state.board, nextBoard);

    {
      board: if (state.board == nextBoard) nextBoard else addBlock(nextBoard),
      score: state.score + score,
      isGameOver: isGameOver(nextBoard)
    }
  }
}
