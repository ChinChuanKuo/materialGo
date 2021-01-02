open ReasonReact;
open Setting;
[%bs.raw {|require('../../scss/Snackbar/snackbarYoutube.scss')|}];

type tupleChildren = (reactElement, reactElement);

let positions = position => {
  let basic = "j1mqxag8";
  switch (position) {
  | "topLeft" => basic ++ " " ++ "youtubeTopLeft"
  | "topRight" => basic ++ " " ++ "youtubeTopRight"
  | "bottomLeft" => basic ++ " " ++ "youtubeBottomLeft"
  | "bottomRight" => basic ++ " " ++ "youtubeBottomRight"
  | _ => basic ++ " " ++ "youtubeBottomLeft"
  };
};

let colors = color =>
  switch (color) {
  | None => "rgba(255,255,255,1)"
  | Some(color) => color
  };

let backgroundColors = backgroundColor =>
  switch (backgroundColor) {
  | None => "rgba(0,0,0,1)"
  | Some(backgroundColor) => backgroundColor
  };

[@react.component]
let make =
    (
      ~showYoutube: option(bool)=?,
      ~position: option(string)=?,
      ~style: option(ReactDOMRe.style)=?,
      ~backgroundColor: option(string)=?,
      ~color: option(string)=?,
      ~children: tupleChildren,
    ) =>
  showYoutube |> disabledObjects
    ? ReactDOMRe.createDOMElementVariadic(
        "div",
        ~props=
          ReactDOMRe.domProps(
            ~className={
              position |> stringObjects |> positions;
            },
            (),
          ),
        [|
          ReactDOMRe.createDOMElementVariadic(
            "div",
            ~props=
              ReactDOMRe.domProps(
                ~style={
                  ReactDOMRe.Style.combine(
                    ReactDOMRe.Style.make(
                      ~backgroundColor={
                        backgroundColor |> backgroundColors;
                      },
                      ~color={
                        color |> colors;
                      },
                      (),
                    ),
                    style |> styleObjects,
                  );
                },
                ~className="j1n0vc23s j1gd6a31 jp78c5zs j18zhp3j",
                (),
              ),
            [|
              ReactDOMRe.createDOMElementVariadic(
                "div",
                ~props=ReactDOMRe.domProps(~className="j3bf3oj", ()),
                [|fst(children)|],
              ),
              ReactDOMRe.createDOMElementVariadic(
                "div",
                ~props=ReactDOMRe.domProps(~className="j1ptu8o8", ()),
                [|snd(children)|],
              ),
            |],
          ),
        |],
      )
    : null;