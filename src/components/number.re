[%bs.raw {|require('./app.css')|}];
open ReasonReact
let component = ReasonReact.statelessComponent("Number");
let s = ReasonReact.string;

let value = num =>
  switch (num) {
    | Some(value) => string_of_int(value)
    | None => ""
  }
let make = (~number, _children) => {
  ...component,
  render: _self =>
    <div className="grid-item">{s(value(number))}</div>
};
