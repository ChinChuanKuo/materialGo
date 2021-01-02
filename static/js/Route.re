open Setting;
[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <NewGramBoard
    autoPath={pathObjects(Js_list.length(url.path), url.path, url.hash)}>
    {switch (url.path) {
     | [] => <Home />
     | _ => <Home />
     }}
  </NewGramBoard>;
};
