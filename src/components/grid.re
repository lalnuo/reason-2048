[%bs.raw {|require('./app.css')|}];
let s = ReasonReact.string;


let component = ReasonReact.statelessComponent("Grid");
let renderList = elems => Array.of_list(elems) |> ReasonReact.array
let make = (~board, ~isGameOver, _children) => {
  ...component,
  render: _self =>
    <div tabIndex={1} className="game-grid">
    {
      switch (isGameOver) {
        | true => <GameOver />
        | false => ReasonReact.null
      }
    }
    {
      List.flatten(board)
        |> List.map(i => <Number number={i} />)
        |> renderList

    }
    </div>,
};
