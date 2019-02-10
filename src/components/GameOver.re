[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("GameOver");
let s = ReasonReact.string;

let make = (_children) => {
  ...component,
  render: _self =>
<div className="game-over">{s("Game over. Press")} <b className="esc">{s("esc")}</b> {s("to restart")}</div>
};
