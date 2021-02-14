open React;
open Together;
open UserMedia;

type state = {
  formLoad: bool,
  showProgress: bool,
  error: bool,
  recorder: element,
};

type action =
  | SettingError
  | SettingFormLoad
  | ActionShowProgress
  | ActionRecorder(element);

let reducer = (state, action) =>
  switch (action) {
  | SettingError => {...state, error: !state.error}
  | SettingFormLoad => {...state, formLoad: !state.formLoad}
  | ActionShowProgress => {...state, showProgress: !state.showProgress}
  | ActionRecorder(recorder) => {...state, recorder}
  };

let initialState = {
  formLoad: false,
  showProgress: false,
  error: false,
  recorder: null,
};

[@react.component]
let make = _ => {
  let (state, dispatch) = useReducer(reducer, initialState);

  let mediaDataAvailable = event => event |> Js.log;

  let getMediaStream = () =>
    Js.Promise.(
      getUserMedia({"audio": false, "video": true})
      |> then_(response =>
           {
             attachMedia(UserMedia.make("video"), response) |> ignore;
             UserMedia.make("video") |> play;
             ActionRecorder(response |> Recorder.make) |> dispatch;
           }
           |> resolve
         )
      |> catch(error => error |> Js.log |> resolve)
      |> ignore
    );

  let recordFile = useCallback(_ => state.recorder |> Recorder.start);

  let screenFile = useCallback(_ => state.recorder |> Recorder.stop);

  let handleScrollBar = event => event |> Js.log;

  useEffect(() => {
    let testId =
      Window.Listeners.add("dataavailable", handleScrollBar, true) |> ignore;
    Some(() => testId);
  });

  useEffect0(() => {
    let timeId = getMediaStream();
    Some(() => timeId);
  });

  <NewInstagram showProgress={state.showProgress} error={state.error}>
    <GridItem
      style=marginAuto
      top="0"
      right="32"
      bottom="0"
      left="32"
      xs="12"
      maxWidth="770px">
      <GridContainer direction="column" justify="center" alignItem="stretch">
        <GridItem top="0" right="0" bottom="0" left="0" xs="auto">
          <Camera width="auto" height="100%" />
        </GridItem>
        <GridItem top="0" right="0" bottom="0" left="0" xs="no">
          <GridContainer direction="row" justify="between" alignItem="center">
            <GridItem top="0" right="0" bottom="0" left="0" xs="no">
              <Button
                enterBackgroundColor="rgba(255,0,0,0.4)"
                downBackgroundColor="rgba(255,0,0,0.2)"
                backgroundColor="rgba(255,255,255,1)"
                color="rgba(255,0,0,1)"
                onClick=recordFile>
                {"Recording" |> string}
              </Button>
            </GridItem>
            <GridItem top="0" right="0" bottom="0" left="0" xs="no">
              <Button
                enterBackgroundColor="rgba(255,0,0,0.4)"
                downBackgroundColor="rgba(255,0,0,0.2)"
                backgroundColor="rgba(255,255,255,1)"
                color="rgba(255,0,0,1)"
                onClick=screenFile>
                {"Screenshot" |> string}
              </Button>
            </GridItem>
          </GridContainer>
        </GridItem>
      </GridContainer>
    </GridItem>
  </NewInstagram>;
};
