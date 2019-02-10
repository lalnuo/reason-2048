[@bs.module "react-swipeable"] external swipeable : ReasonReact.reactClass = "Swipeable";

let make = (~onSwipeLeft, ~onSwipeUp, ~onSwipeDown, ~onSwipeRight, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=swipeable,
    ~props={
      "onSwipedLeft": onSwipeLeft,
      "onSwipedRight": onSwipeRight,
      "onSwipedDown": onSwipeDown,
      "onSwipedUp": onSwipeUp,
      "preventDefaultTouchmoveEvent": true
    },
    children
  );
