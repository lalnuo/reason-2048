open Jest;

describe("moving to right", () => {
  test("with one element moves it to right", _ => {
    let startingRow = [Some(1), None, None, None];
    let movedRow = [None, None, None, Some(1)];
    Expect.(expect(Game.moveRowRight(startingRow)) |> toEqual(movedRow));
  });

  test("with one element in the middle it is moved to the right", _ => {
    let startingRow = [None, Some(1), None, None];
    let movedRow = [None, None, None, Some(1)];
    Expect.(expect(Game.moveRowRight(startingRow)) |> toEqual(movedRow));
  });
});

describe("moving to left", () => {
  test("with one element moves it to left", _ => {
    let startingRow = [None, None, None, Some(1)];
    let movedRow = [Some(1), None, None, None];
    Expect.(expect(Game.moveRowLeft(startingRow)) |> toEqual(movedRow));
  });

  test("with one element in the middle it is moved to the left", _ => {
    let startingRow = [None, None, Some(1), None];
    let movedRow = [Some(1), None, None, None];
    Expect.(expect(Game.moveRowLeft(startingRow)) |> toEqual(movedRow));
  });
});

/*test("with two different elements both are moved to right", _ =>*/
/*Expect.(*/
/*expect(Game.moveRowRight([Some(1), Some(2), None, None])) |> toEqual([None, None, Some(1), Some(2)])*/
/*)*/
/*);*/
/*test("with two similar elements they are merged and moved to right", _ =>*/
/*Expect.(expect(Game.moveRowRight([Some(1), Some(1), None, None])) |> toEqual([None, None, None, Some(2)]))*/
/*);*/
