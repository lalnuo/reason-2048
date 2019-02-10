let onlyNones = nums => !List.exists(i => i != None, nums)

let optionSum = List.fold_left((acc, i) => {
  switch (i) {
    | Some(i) => acc + i
    | None => acc
  }
}, 0);

let rec removeN = (items, n) =>
  switch (items) {
    | [a, ...rest] when a == n => rest
    | [a, ...rest] => [a, ...removeN(rest, n)]
    | [] => []
  }

let replace = (items, nth, item) => {
  let splitted = Belt.List.splitAt(items, nth)
  switch (splitted) {
    | Some((head, tail)) => head @ [item] @ List.tl(tail)
    | None => items
  }
}
