[%bs.raw {|require('./app.css')|}];

let component = ReasonReact.statelessComponent("GameOver");
let s = ReasonReact.string;

let make = (~restartGame, _children) => {
  ...component,
  render: _self =>
<div onClick={restartGame} className="game-over">
  <span className="game-over-text">{s("Game over. Press esc to restart or click the screen")}</span>
</div>
};
