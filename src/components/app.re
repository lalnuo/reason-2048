[%bs.raw {|require('./app.css')|}];
open ReasonReact
let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="content">
      <div className="header">{string("2048")}</div>
        <Grid/>
      </div>
    </div>,
};
