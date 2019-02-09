open AvaBucklescript.Sync;
open Game;

test("Moving to right with one number", t => {
  let start = [Some(1), None, None, None];
  let afterMoving = [None, None, None, Some(1)];

  t.deepEqual(moveRowRight(start), afterMoving);
  t.pass();
});

test("Moving to right with two different numbers", t => {
  let start = [Some(1), Some(2), None, None];
  let afterMoving = [None, None, Some(1), Some(2)];

  t.deepEqual(moveRowRight(start), afterMoving);
  t.pass();
});

test("Moving to left with one number", t => {
  let start = [None, None, None, Some(1)];
  let afterMoving = [Some(1), None, None, None];

  t.deepEqual(moveRowLeft(start), afterMoving);
  t.pass();
});

test("Moving to left with two different numbers", t => {
  let start = [None, None, Some(1), Some(2)];
  let afterMoving = [Some(1), Some(2), None, None];

  t.deepEqual(moveRowLeft(start), afterMoving);
  t.pass();
});

test("number joiner joins neighbours", t => {
  let start = [Some(2), Some(2), Some(2), None];
  let afterMoving = [Some(4), Some(2), None, None];
  t.deepEqual(numberJoiner(start), afterMoving);
  t.pass();
});

test("number joiner joins multiple neighbours", t => {
  let start = [Some(2), Some(2), Some(2), Some(2)];
  let afterMoving = [Some(4), Some(4), None, None];
  t.deepEqual(numberJoiner(start), afterMoving);
  t.pass();
});

test("number joiner joins numbers where the first one can not be joined", t => {
  let start = [Some(2), Some(4), Some(4), None];
  let afterMoving = [Some(2), Some(8), None, None];
  t.deepEqual(numberJoiner(start), afterMoving);
  t.pass();
});

test(
  "number joiner joins rows when there is Nones between joinable numbers", t => {
  let start = [Some(4), None, Some(4), None];
  let afterMoving = [Some(8), None, None, None];
  t.deepEqual(numberJoiner(start), afterMoving);
  t.pass();
});

test("getting vertical rows", t => {
  let matrix = [
    [Some(1), Some(2), Some(3)],
    [Some(4), Some(5), Some(6)],
    [Some(7), Some(8), Some(9)],
  ];

  let verticalRowsResult = [
    [Some(1), Some(4), Some(7)],
    [Some(2), Some(5), Some(8)],
    [Some(3), Some(6), Some(9)],
  ];
  t.deepEqual(transpose(matrix), verticalRowsResult);
  t.pass();
});

test("Moving up", t => {
  let start = [
    [None, Some(1), None],
    [None, Some(1), None],
    [None, None, None],
  ];
  let afterMoving = [
    [None, Some(2), None],
    [None, None, None],
    [None, None, None],
  ];
  t.deepEqual(moveUp(start), afterMoving);
  t.pass();
});

test("Moving down", t => {
  let start = [
    [None, Some(1), None],
    [None, Some(1), None],
    [None, None, None],
  ];
  let afterMoving = [
    [None, None, None],
    [None, None, None],
    [None, Some(2), None],
  ];
  t.deepEqual(moveDown(start), afterMoving);
  t.pass();
});

test("has nones returns true when there are nones", t => {
  let state = [
    [Some(1), Some(1), Some(1)],
    [None, Some(1), None],
    [None, None, None],
  ];
  t.deepEqual(hasNones(state), true);
  t.pass();
});

test("has nones returns false when there are nones", t => {
  let state = [
    [Some(1), Some(1), Some(1)],
    [Some(2), Some(1), Some(2)],
    [Some(2), Some(2), Some(2)],
  ];
  t.deepEqual(hasNones(state), false);
  t.pass();
});

test("is game over returns true when game is over", t => {
  let state = [
    [Some(1), Some(3), Some(2)],
    [Some(3), Some(5), Some(4)],
    [Some(5), Some(6), Some(2)],
  ];
  t.deepEqual(isGameOver(state), true);
  t.pass();
})
