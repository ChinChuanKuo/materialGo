// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Caml_format from "bs-platform/lib/es6/caml_format.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Setting$BtsCore from "../../../setting/Setting.bs.js";

((require('../../scss/PasteBoard/pasteBoard.scss')));

function widths(width) {
  if (width !== undefined) {
    return width;
  } else {
    return "calc(100% - 8px)";
  }
}

function heights(height) {
  if (height !== undefined) {
    return height + "px";
  } else {
    return "250px";
  }
}

function insideWidths(borderWidth) {
  if (borderWidth !== undefined) {
    return "calc(100% - " + (String((Caml_format.caml_int_of_string(borderWidth) << 1)) + "px)");
  } else {
    return "calc(100% - 8px)";
  }
}

function insideHeights(height, borderWidth) {
  if (height !== undefined) {
    if (borderWidth !== undefined) {
      return "calc(" + (height + (" - " + (String((Caml_format.caml_int_of_string(borderWidth) << 1)) + "px)")));
    } else {
      return "calc(" + (height + " - 8px)");
    }
  } else if (borderWidth !== undefined) {
    return "calc(250px - " + (String((Caml_format.caml_int_of_string(borderWidth) << 1)) + "px)");
  } else {
    return "242px";
  }
}

function borderRadiuses(borderRadius) {
  if (borderRadius !== undefined) {
    return borderRadius + "px";
  } else {
    return "10px";
  }
}

function borderWidths(borderWidth) {
  if (borderWidth !== undefined) {
    return borderWidth + "px";
  } else {
    return "4px";
  }
}

function borderStyles(borderStyle) {
  if (borderStyle !== undefined) {
    return borderStyle;
  } else {
    return "dashed";
  }
}

function borderColors(borderColor) {
  if (borderColor !== undefined) {
    return borderColor;
  } else {
    return "rgba(255,0,0,0.8)";
  }
}

function PasteBoard(Props) {
  var style = Props.style;
  var width = Props.width;
  var height = Props.height;
  var borderRadius = Props.borderRadius;
  var borderWidth = Props.borderWidth;
  var borderStyle = Props.borderStyle;
  var borderColor = Props.borderColor;
  var onDragOver = Props.onDragOver;
  var onDragLeave = Props.onDragLeave;
  var onDrop = Props.onDrop;
  var children = Props.children;
  var tmp = {
    style: {
      height: heights(height),
      width: width !== undefined ? width : "calc(100% - 8px)"
    }
  };
  if (onDragLeave !== undefined) {
    tmp.onDragLeave = Caml_option.valFromOption(onDragLeave);
  }
  if (onDragOver !== undefined) {
    tmp.onDragOver = Caml_option.valFromOption(onDragOver);
  }
  if (onDrop !== undefined) {
    tmp.onDrop = Caml_option.valFromOption(onDrop);
  }
  return React.createElement("div", tmp, React.createElement("div", {
                  className: "bgScalePaste",
                  style: {
                    height: heights(height),
                    width: "100%",
                    borderRadius: borderRadiuses(borderRadius)
                  }
                }, React.createElement("div", {
                      className: "innerPaste",
                      style: Object.assign(({}), {
                            borderColor: borderColor !== undefined ? borderColor : "rgba(255,0,0,0.8)",
                            borderStyle: borderStyle !== undefined ? borderStyle : "dashed",
                            borderWidth: borderWidths(borderWidth),
                            height: insideHeights(height, borderWidth),
                            width: insideWidths(borderWidth),
                            borderRadius: borderRadiuses(borderRadius)
                          }, Setting$BtsCore.styleObjects(style))
                    }, children)));
}

var make = PasteBoard;

export {
  widths ,
  heights ,
  insideWidths ,
  insideHeights ,
  borderRadiuses ,
  borderWidths ,
  borderStyles ,
  borderColors ,
  make ,
  
}
/*  Not a pure module */
