open React;
open Setting;
[%bs.raw {|require('../../scss/Avatar/avatar.scss')|}];

type state = {
  enter: bool,
  down: bool,
};

type action =
  | MouseEnterLeave(bool)
  | MouseUpDown(bool);

let reducer = (state, action) =>
  switch (action) {
  | MouseEnterLeave(enter) => {enter, down: enter ? state.down : false}
  | MouseUpDown(down) => {...state, down}
  };

let initialState = {enter: false, down: false};

let margins = value =>
  switch (value) {
  | None => "10px"
  | Some(value) => value ++ "px"
  };

let widths = value =>
  switch (value) {
  | None => "1px"
  | Some(value) => value ++ "px"
  };

let styles = value =>
  switch (value) {
  | None => "solid"
  | Some(value) => value
  };

let colors = value =>
  switch (value) {
  | None => "transparent"
  | Some(value) => value
  };

let enterColors = value =>
  switch (value) {
  | None => "rgba(255,0,0,1)"
  | Some(value) => value
  };

let backgroundColors = value =>
  switch (value) {
  | None => "#bdbdbd"
  | Some(value) => value
  };

let colors = value =>
  switch (value) {
  | None => "#fafafa"
  | Some(value) => value
  };

[@react.component]
let make =
    (
      ~style: option(ReactDOMRe.style)=?,
      ~top: option(string)=?,
      ~right: option(string)=?,
      ~bottom: option(string)=?,
      ~left: option(string)=?,
      ~color: option(string)=?,
      ~downColor: option(string)=?,
      ~enterColor: option(string)=?,
      ~borderWidth: option(string)=?,
      ~downBorderWidth: option(string)=?,
      ~enterBorderWidth: option(string)=?,
      ~borderStyle: option(string)=?,
      ~downBorderStyle: option(string)=?,
      ~enterBorderStyle: option(string)=?,
      ~borderColor: option(string)=?,
      ~downBorderColor: option(string)=?,
      ~enterBorderColor: option(string)=?,
      ~backgroundColor: option(string)=?,
      ~downBackgroundColor: option(string)=?,
      ~enterBackgroundColor: option(string)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~children,
    ) => {
  let (state, dispatch) = useReducer(reducer, initialState);
  ReactDOMRe.createDOMElementVariadic(
    "header",
    ~props=
      ReactDOMRe.domProps(
        ~style={
          ReactDOMRe.Style.combine(
            ReactDOMRe.Style.make(
              ~marginTop={
                top |> margins;
              },
              ~marginRight={
                right |> margins;
              },
              ~marginBottom={
                bottom |> margins;
              },
              ~marginLeft={
                left |> margins;
              },
              ~color={
                switch (state.enter, state.down) {
                | (true, false) => enterColor |> colors
                | (true, true) => downColor |> colors
                | (_, _) => color |> colors
                };
              },
              ~borderWidth={
                switch (state.enter, state.down) {
                | (true, false) => enterBorderWidth |> widths
                | (true, true) => downBorderWidth |> widths
                | (_, _) => borderWidth |> widths
                };
              },
              ~borderStyle={
                switch (state.enter, state.down) {
                | (true, false) => enterBorderStyle |> styles
                | (true, true) => downBorderStyle |> styles
                | (_, _) => borderStyle |> styles
                };
              },
              ~borderColor={
                switch (state.enter, state.down) {
                | (true, false) => enterBorderColor |> enterColors
                | (true, true) => downBorderColor |> enterColors
                | (_, _) => borderColor |> colors
                };
              },
              ~backgroundColor={
                switch (state.enter, state.down) {
                | (true, false) => enterBackgroundColor |> backgroundColors
                | (true, true) => downBackgroundColor |> backgroundColors
                | (_, _) => backgroundColor |> backgroundColors
                };
              },
              ~cursor="pointer",
              (),
            ),
            style |> styleObjects,
          );
        },
        ~className="j4f2n9i",
        ~onMouseDown=_ => MouseUpDown(true) |> dispatch,
        ~onMouseUp=_ => MouseUpDown(false) |> dispatch,
        ~onMouseEnter=_ => MouseEnterLeave(true) |> dispatch,
        ~onMouseLeave=_ => MouseEnterLeave(false) |> dispatch,
        ~onClick?,
        (),
      ),
    [|children|],
  );
};
