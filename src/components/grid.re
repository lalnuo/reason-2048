[%bs.raw {|require('./app.css')|}];
open Game
type state = GameState
let s = ReasonReact.string;

type action =
  | KeyDown(int)

let component = ReasonReact.reducerComponent("Grid");

let renderList = elems => Array.of_list(elems) |> ReasonReact.array
let make = (_children) => {
  ...component,
  initialState: () => {
    {
      score: 0,
      board: newGame()
    }
  },
  reducer: (action, state) => {
    switch (action) {
      | KeyDown(27) => ReasonReact.Update(play(Restart, state))
      | KeyDown(37) => ReasonReact.Update(play(MoveLeft, state))
      | KeyDown(38) => ReasonReact.Update(play(MoveUp, state))
      | KeyDown(39) => ReasonReact.Update(play(MoveRight, state))
      | KeyDown(40) => ReasonReact.Update(play(MoveDown, state))
      | KeyDown(_) => ReasonReact.NoUpdate
    }
  },
  render: self =>
    <div tabIndex={1} onKeyDown={event => self.send(KeyDown(ReactEvent.Keyboard.which(event)))} className="game-grid">
    {
      List.flatten(self.state.board)
        |> List.map(i => <Number number={i} />)
        |> renderList

    }
    </div>,
};
