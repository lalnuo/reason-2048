open Helpers
open AvaBucklescript.Sync;

test("remove N removes first instance of N CASE 1", t => {
  t.deepEqual(removeN([1, 1, 2, 3], 1), [1, 2, 3]);
});

test("remove N removes first instance of N CASE 2", t => {
  t.deepEqual(removeN([1, 2, 2, 3], 2), [1, 2, 3]);
});
