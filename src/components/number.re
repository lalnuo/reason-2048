[%bs.raw {|require('./app.css')|}];
open ReasonReact
let component = ReasonReact.statelessComponent("Number");
let s = ReasonReact.string;

let value = num =>
  switch (num) {
    | Some(value) => string_of_int(value)
    | None => ""
  }

let toShade = (base, multiplier, num) =>
  (base /. float_of_int(num) ** multiplier)
  |> int_of_float
  |> string_of_int



 /* Pink: "rgb( " ++ toShade(255.0 , 0., a) ++ ", " ++ toShade(220.0,0.125, a) ++ ", " ++ toShade(230.0, 0.125, a) ++ ")" */


let getBackgroundColor = value => {
  switch (value) {
    | Some(a) => {
      "rgb( " ++ toShade(255.0 , 0., a) ++ ", " ++ toShade(220.0,0.125, a) ++ ", " ++ toShade(230.0, 0.125, a) ++ ")"
    }
    | None => "rgb(178, 178, 178)"
  }
}

let make = (~number, _children) => {
  ...component,
  render: _self =>
    <div
      style={ReactDOMRe.Style.make(~backgroundColor={getBackgroundColor(number)}, ())}
      className="grid-item"
    >
      {s(value(number))}
    </div>
};
