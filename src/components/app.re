[%bs.raw {|require('./app.css')|}];
open ReasonReact
open Game
let s = ReasonReact.string;

type state = GameState
type action = | KeyDown(int);
let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState: getInitialState,
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
    <div tabIndex={1} onKeyDown={event => self.send(KeyDown(ReactEvent.Keyboard.which(event)))} className="App">
      <div className="content">
      <div className="header-and-score">
        <div className="header">{string("2048")}</div>
        <div className="score">{s("Score: " ++ string_of_int(self.state.score))}</div>
      </div>
      <Grid
        isGameOver={self.state.isGameOver}
        board={self.state.board}
      />
      </div>
    </div>,
};
