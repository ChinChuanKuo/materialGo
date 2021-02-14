open Setting;
[%bs.raw {|require('../../scss/Badge/badge.scss')|}];

let others = value =>
  switch (value) {
  | None => "auto"
  | Some(value) => value
  };

let transforms = (key, value) =>
  switch (key) {
  | None =>
    switch (value) {
    | None => "translate(15px, -15px)"
    | _ => "translate(-15px, -15px)"
    }
  | _ =>
    switch (value) {
    | None => "translate(15px, 15px)"
    | _ => "translate(-15px, 15px)"
    }
  };

let colors = color =>
  switch (color) {
  | None => "rgba(255,255,255,1)"
  | Some(color) => color
  };

let backgroundColors = value =>
  switch (value) {
  | None => "#3f51b5"
  | Some(value) => value
  };

[@react.component]
let make =
    (
      ~style: option(ReactDOMRe.style)=?,
      ~vertical: option(string)=?,
      ~horizontal: option(string)=?,
      ~top: option(string)=?,
      ~right: option(string)=?,
      ~bottom: option(string)=?,
      ~left: option(string)=?,
      ~color: option(string)=?,
      ~backgroundColor: option(string)=?,
      ~children,
    ) =>
  ReactDOMRe.createDOMElementVariadic(
    "span",
    ~props=
      ReactDOMRe.domProps(
        ~style={
          ReactDOMRe.Style.combine(
            ReactDOMRe.Style.make(
              ~top={
                top |> others;
              },
              ~right={
                right |> others;
              },
              ~bottom={
                bottom |> others;
              },
              ~left={
                left |> others;
              },
              ~transform={
                transforms(vertical, horizontal);
              },
              ~color={
                color |> colors;
              },
              ~backgroundColor={
                backgroundColor |> backgroundColors;
              },
              (),
            ),
            style |> styleObjects,
          );
        },
        ~className="j1nwm6bj j177wmhi",
        (),
      ),
    [|children|],
  );
