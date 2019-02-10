[@bs.module "react-touch"] external swipeable : ReasonReact.reactClass = "Swipeable";

let make = (~onSwipeLeft, ~onSwipeUp, ~onSwipeDown, ~onSwipeRight, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=swipeable,
    ~props={
      "onSwipeLeft": onSwipeLeft,
      "onSwipeRight": onSwipeRight,
      "onSwipeDown": onSwipeDown,
      "onSwipeUp": onSwipeUp
    },
    children
  );
