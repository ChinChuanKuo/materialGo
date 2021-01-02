[@react.component]
let make = (~children) =>
  ReactDOMRe.createDOMElementVariadic(
    "li",
    ~props=
      ReactDOMRe.domProps(
        ~style={
          ReactDOMRe.Style.make(
            ~display="flex",
            ~userSelect="none",
            ~marginRight="8px",
            ~marginLeft="8px",
            (),
          );
        },
        (),
      ),
    [|children|],
  );