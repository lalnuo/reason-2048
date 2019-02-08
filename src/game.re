type numbers = list(list(option(int)));

let isNumber = (maybeNum: option(int)) =>
  switch (maybeNum) {
  | Some(_) => true
  | None => false
  };

let isNone = (maybeNum: option(int)) => !isNumber(maybeNum);

let moveRowRight = (numbers: list(option(int))) =>
  List.append(List.filter(isNone, numbers), List.filter(isNumber, numbers));

let moveRowLeft = (numbers: list(option(int))) =>
  List.append(List.filter(isNumber, numbers), List.filter(isNone, numbers));

let moveRight = (board: numbers): numbers => {
  List.map(moveRowRight, board);
};
