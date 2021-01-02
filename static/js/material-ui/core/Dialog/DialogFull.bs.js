// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Setting$BtsCore from "../../../setting/Setting.bs.js";

((require('../../scss/Dialog/dialogFull.scss')));

function visibilitys(showAnimation) {
  if (showAnimation) {
    return "";
  } else {
    return "hidden";
  }
}

function opacitys(showAnimation) {
  if (showAnimation) {
    return "1";
  } else {
    return "0";
  }
}

function outtransitions(showAnimation) {
  if (showAnimation) {
    return "opacity 225ms cubic-bezier(0.4, 0, 0.2, 1) 0ms";
  } else {
    return "opacity 195ms cubic-bezier(0.4, 0, 0.2, 1) 0ms";
  }
}

function transforms(showAnimation) {
  if (showAnimation) {
    return "translate(0px, 0px)";
  } else {
    return "translateY(100vh) translateY(0px)";
  }
}

function transitions(showAnimation) {
  if (showAnimation) {
    return "transform 225ms cubic-bezier(0, 0, 0.2, 1) 0ms";
  } else {
    return "";
  }
}

function backgroundColors(backgroundColor) {
  if (backgroundColor !== undefined) {
    return backgroundColor;
  } else {
    return "rgba(255,255,255,1)";
  }
}

function DialogFull(Props) {
  var showAnimation = Props.showAnimation;
  var style = Props.style;
  var backgroundColor = Props.backgroundColor;
  var children = Props.children;
  var showAnimation$1 = Setting$BtsCore.disabledObjects(showAnimation);
  var showAnimation$2 = Setting$BtsCore.disabledObjects(showAnimation);
  var showAnimation$3 = Setting$BtsCore.disabledObjects(showAnimation);
  var showAnimation$4 = Setting$BtsCore.disabledObjects(showAnimation);
  var showAnimation$5 = Setting$BtsCore.disabledObjects(showAnimation);
  return React.createElement("div", {
              className: "jupvbsj",
              role: "dialog",
              style: {
                visibility: showAnimation$1 ? "" : "hidden"
              }
            }, React.createElement("div", {
                  className: "j1hwasmh",
                  style: {
                    opacity: showAnimation$2 ? "1" : "0",
                    transition: showAnimation$3 ? "opacity 225ms cubic-bezier(0.4, 0, 0.2, 1) 0ms" : "opacity 195ms cubic-bezier(0.4, 0, 0.2, 1) 0ms"
                  }
                }), React.createElement("div", {
                  className: "jlbc39s j1olfzzh",
                  style: {
                    transition: showAnimation$4 ? "transform 225ms cubic-bezier(0, 0, 0.2, 1) 0ms" : "",
                    transform: showAnimation$5 ? "translate(0px, 0px)" : "translateY(100vh) translateY(0px)"
                  }
                }, React.createElement("div", {
                      className: "j1iocy8x j116tjkxl j1bnredml jnw24a9",
                      style: Object.assign(({}), {
                            backgroundColor: backgroundColor !== undefined ? backgroundColor : "rgba(255,255,255,1)"
                          }, Setting$BtsCore.styleObjects(style))
                    }, children)));
}

var make = DialogFull;

export {
  visibilitys ,
  opacitys ,
  outtransitions ,
  transforms ,
  transitions ,
  backgroundColors ,
  make ,
  
}
/*  Not a pure module */