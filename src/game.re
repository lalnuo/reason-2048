
let onlyNones = nums => !List.exists(i => i != None, nums)
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

let boardSum = (board: list(list(option(int)))) =>
  List.flatten(board)
  |> List.fold_left(
       (acc, i) =>
         switch (i) {
         | Some(i) => acc + i
         | None => acc
         },
       0,
     );


