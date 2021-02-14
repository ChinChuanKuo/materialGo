open Setting;
[%bs.raw {|require('../../scss/AppBar/appBar.scss')|}];

let positions = value =>
  switch (value) {
  | None => "fixed"
  | Some(value) => value
  };

let colors = value =>
  switch (value) {
  | None => "#3f51b5"
  | Some(value) => value
  };

let zIndexs = value =>
  switch (value) {
  | None => "1200"
  | Some(value) => value
  };

let minHeights = value =>
  switch (value) {
  | None => "64px"
  | Some(value) => value ++ "px"
  };

[@react.component]
let make =
    (
      ~style: option(ReactDOMRe.style)=?,
      ~position: option(string)=?,
      ~color: option(string)=?,
      ~zIndex: option(string)=?,
      ~minHeight: option(string)=?,
      ~children,
    ) =>
  ReactDOMRe.createDOMElementVariadic(
    "header",
    ~props=
      ReactDOMRe.domProps(
        ~style={
          ReactDOMRe.Style.combine(
            ReactDOMRe.Style.make(
              ~position={
                position |> positions;
              },
              ~backgroundColor={
                color |> colors;
              },
              ~zIndex={
                zIndex |> zIndexs;
              },
              (),
            ),
            style |> styleObjects,
          );
        },
        ~className="jss99 jss98 jss113",
        (),
      ),
    [|
      ReactDOMRe.createDOMElementVariadic(
        "div",
        ~props=
          ReactDOMRe.domProps(
            ~style={
              ReactDOMRe.Style.make(
                ~minHeight={
                  minHeight |> minHeights;
                },
                (),
              );
            },
            ~className="jss134 jss136",
            (),
          ),
        [|children|],
      ),
    |],
  );
