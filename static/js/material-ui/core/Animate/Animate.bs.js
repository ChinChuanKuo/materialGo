// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Setting$BtsCore from "../../../setting/Setting.bs.js";

function attributeNames(value) {
  if (value !== undefined) {
    return value;
  } else {
    return "";
  }
}

function calcModes(value) {
  if (value !== undefined) {
    return value;
  } else {
    return "linear";
  }
}

function fills(value) {
  if (value !== undefined) {
    return value;
  } else {
    return "freeze";
  }
}

function durs(value) {
  if (value !== undefined) {
    return value + "s";
  } else {
    return "1s";
  }
}

function others(value) {
  if (value !== undefined) {
    return value;
  } else {
    return "0";
  }
}

function Animate(Props) {
  var style = Props.style;
  var name = Props.name;
  var mode = Props.mode;
  var fill = Props.fill;
  var dur = Props.dur;
  var from = Props.from;
  var to_ = Props.to_;
  return React.createElement("animate", {
              style: Setting$BtsCore.styleObjects(style),
              attributeName: name !== undefined ? name : "",
              calcMode: mode !== undefined ? mode : "linear",
              dur: durs(dur),
              fill: fill !== undefined ? fill : "freeze",
              from: from !== undefined ? from : "0",
              to: to_ !== undefined ? to_ : "0"
            });
}

var make = Animate;

export {
  attributeNames ,
  calcModes ,
  fills ,
  durs ,
  others ,
  make ,
  
}
/* react Not a pure module */
