open Setting;

let attributeNames = value =>
  switch (value) {
  | None => ""
  | Some(value) => value
  };

let calcModes = value =>
  switch (value) {
  | None => "linear"
  | Some(value) => value
  };

let fills = value =>
  switch (value) {
  | None => "freeze"
  | Some(value) => value
  };

let durs = value =>
  switch (value) {
  | None => "1s"
  | Some(value) => value ++ "s"
  };

let others = value =>
  switch (value) {
  | None => "0"
  | Some(value) => value
  };

[@react.component]
let make =
    (
      ~style: option(ReactDOMRe.style)=?,
      ~name: option(string)=?,
      ~mode: option(string)=?,
      ~fill: option(string)=?,
      ~dur: option(string)=?,
      ~from: option(string)=?,
      ~to_: option(string)=?,
    ) =>
  ReactDOMRe.createDOMElementVariadic(
    "animate",
    ~props=
      ReactDOMRe.domProps(
        ~style={
          style |> styleObjects;
        },
        ~attributeName={
          name |> attributeNames;
        },
        ~calcMode={
          mode |> calcModes;
        },
        ~fill={
          fill |> fills;
        },
        ~dur={
          dur |> durs;
        },
        ~from={
          from |> others;
        },
        ~to_={
          to_ |> others;
        },
        (),
      ),
    [||],
  );
