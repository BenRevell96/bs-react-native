module type FlatListComponent = {
  let scrollToEnd: (ReasonReact.reactRef, ~animated: bool) => unit;

  let scrollToIndex:
    (
      ReasonReact.reactRef,
      ~index: int,
      ~animated: bool=?,
      ~viewOffset: int=?,
      ~viewPosition: int=?,
      unit
    ) =>
    unit;

  let scrollToItem:
    (
      ReasonReact.reactRef,
      ~item: 'item,
      ~animated: bool=?,
      ~viewPosition: int=?,
      unit
    ) =>
    unit;

  let scrollToOffset:
    (ReasonReact.reactRef, ~offset: int=?, ~animated: bool=?, unit) => unit;

  [@bs.send] external recordInteraction : ReasonReact.reactRef => unit = "";

  type renderBag('item) = {
    item: 'item,
    index: int,
  };

  type renderItem('item);

  let renderItem:
    (renderBag('item) => ReasonReact.reactElement) => renderItem('item);

  type separatorComponent('item);

  type separatorProps('item) = {
    highlighted: bool,
    leadingItem: option('item),
  };

  let separatorComponent:
    (separatorProps('item) => ReasonReact.reactElement) =>
    separatorComponent('item);

  let make:
    (
      ~data: array('item),
      ~renderItem: renderItem('item),
      ~keyExtractor: ('item, int) => string,
      ~itemSeparatorComponent: separatorComponent('item)=?,
      ~bounces: bool=?,
      ~listFooterComponent: ReasonReact.reactElement=?,
      ~listHeaderComponent: ReasonReact.reactElement=?,
      ~columnWrapperStyle: Style.t=?,
      ~extraData: 'any=?,
      ~getItemLayout: (option(array('item)), int) =>
                      {
                        .
                        "length": int,
                        "offset": int,
                        "index": int,
                      }
                        =?,
      ~horizontal: bool=?,
      ~initialNumToRender: int=?,
      ~initialScrollIndex: int=?,
      ~inverted: bool=?,
      ~numColumns: 'int=?,
      ~onEndReached: {. "distanceFromEnd": float} => unit=?,
      ~onEndReachedThreshold: float=?,
      ~onRefresh: unit => unit=?,
      ~onViewableItemsChanged: {
                                 .
                                 "viewableItems":
                                   array(
                                     {
                                       .
                                       "item": 'item,
                                       "key": string,
                                       "index": Js.undefined(int),
                                       "isViewable": bool,
                                       "section": Js.t({.}),
                                     },
                                   ),
                                 "changed":
                                   array(
                                     {
                                       .
                                       "item": 'item,
                                       "key": string,
                                       "index": Js.undefined(int),
                                       "isViewable": bool,
                                       "section": Js.t({.}),
                                     },
                                   ),
                               }
                                 =?,
      ~overScrollMode: [ | `auto | `always | `never]=?,
      ~pagingEnabled: bool=?,
      ~refreshing: bool=?,
      ~removeClippedSubviews: bool=?,
      ~scrollEnabled: bool=?,
      ~showsHorizontalScrollIndicator: bool=?,
      ~showsVerticalScrollIndicator: bool=?,
      ~windowSize: int=?,
      ~maxToRenderPerBatch: int=?,
      ~viewabilityConfig: Js.t({.})=?,
      ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
      ~style: Style.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent = (Impl: View.Impl) : FlatListComponent => {
  [@bs.send]
  external _scrollToEnd : (ReasonReact.reactRef, {. "animated": bool}) => unit =
    "scrollToEnd";

  let scrollToEnd = (ref, ~animated) =>
    _scrollToEnd(ref, {"animated": animated});

  [@bs.send]
  external _scrollToIndex :
    (
      ReasonReact.reactRef,
      {
        .
        "index": int,
        "viewOffset": Js.undefined(int),
        "viewPosition": Js.undefined(int),
        "animated": Js.undefined(bool),
      }
    ) =>
    unit =
    "_scrollToIndex";

  let scrollToIndex =
      (ref, ~index, ~animated=?, ~viewOffset=?, ~viewPosition=?, ()) =>
    _scrollToIndex(
      ref,
      Js.Undefined.(
        {
          "index": index,
          "viewOffset": fromOption(viewOffset),
          "viewPosition": fromOption(viewPosition),
          "animated": fromOption(animated),
        }
      ),
    );

  [@bs.send]
  external _scrollToItem :
    (
      ReasonReact.reactRef,
      {
        .
        "item": 'item,
        "viewPosition": Js.undefined(int),
        "animated": Js.undefined(bool),
      }
    ) =>
    unit =
    "_scrollToIndex";

  let scrollToItem = (ref, ~item, ~animated=?, ~viewPosition=?, ()) =>
    _scrollToItem(
      ref,
      Js.Undefined.(
        {
          "item": item,
          "viewPosition": fromOption(viewPosition),
          "animated": fromOption(animated),
        }
      ),
    );

  [@bs.send]
  external _scrollToOffset :
    (
      ReasonReact.reactRef,
      {
        .
        "offset": Js.undefined(int),
        "animated": Js.undefined(bool),
      }
    ) =>
    unit =
    "_scrollToIndex";

  let scrollToOffset = (ref, ~offset=?, ~animated=?, ()) =>
    _scrollToOffset(
      ref,
      Js.Undefined.(
        {"offset": fromOption(offset), "animated": fromOption(animated)}
      ),
    );

  [@bs.send] external recordInteraction : ReasonReact.reactRef => unit = "";

  type jsRenderBag('item) = {
    .
    "item": 'item,
    "index": int,
  };

  type renderBag('item) = {
    item: 'item,
    index: int,
  };

  type renderItem('item) = jsRenderBag('item) => ReasonReact.reactElement;

  let renderItem =
      (reRenderItem: renderBag('item) => ReasonReact.reactElement)
      : renderItem('item) =>
    (jsRenderBag: jsRenderBag('item)) =>
      reRenderItem({item: jsRenderBag##item, index: jsRenderBag##index});

  type jsSeparatorProps('item) = {
    .
    "highlighted": bool,
    "leadingItem": Js.Undefined.t('item),
  };

  type separatorProps('item) = {
    highlighted: bool,
    leadingItem: option('item),
  };

  type separatorComponent('item) =
    jsSeparatorProps('item) => ReasonReact.reactElement;

  let separatorComponent =
      (
        reSeparatorComponent:
          separatorProps('item) => ReasonReact.reactElement,
      )
      : separatorComponent('item) =>
    (jsSeparatorProps: jsSeparatorProps('item)) =>
      reSeparatorComponent({
        highlighted: jsSeparatorProps##highlighted,
        leadingItem: Js.Undefined.toOption(jsSeparatorProps##leadingItem),
      });

  let make =
      (
        ~data: array('item),
        ~renderItem: renderItem('item),
        ~keyExtractor: ('item, int) => string,
        ~itemSeparatorComponent: option(separatorComponent('item))=?,
        ~bounces=?,
        ~listFooterComponent=?,
        ~listHeaderComponent=?,
        ~columnWrapperStyle=?,
        ~extraData=?,
        ~getItemLayout=?,
        ~horizontal=?,
        ~initialNumToRender=?,
        ~initialScrollIndex=?,
        ~inverted=?,
        ~numColumns=?,
        ~onEndReached=?,
        ~onEndReachedThreshold=?,
        ~onRefresh=?,
        ~onViewableItemsChanged=?,
        ~overScrollMode=?,
        ~pagingEnabled=?,
        ~refreshing=?,
        ~removeClippedSubviews=?,
        ~scrollEnabled=?,
        ~showsHorizontalScrollIndicator=?,
        ~showsVerticalScrollIndicator=?,
        ~windowSize=?,
        ~maxToRenderPerBatch=?,
        ~viewabilityConfig=?,
        ~onScroll=?,
        ~style=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props=
        Js.Undefined.(
          {
            "bounces": fromOption(UtilsRN.optBoolToOptJsBoolean(bounces)),
            "ItemSeparatorComponent": fromOption(itemSeparatorComponent),
            "ListFooterComponent": fromOption(listFooterComponent),
            "ListHeaderComponent": fromOption(listHeaderComponent),
            "columnWrapperStyle": fromOption(columnWrapperStyle),
            "data": data,
            "extraData": fromOption(extraData),
            "getItemLayout":
              fromOption(
                UtilsRN.option_map(
                  (f, data, index) => f(Js.Undefined.toOption(data), index),
                  getItemLayout,
                ),
              ),
            "horizontal":
              fromOption(UtilsRN.optBoolToOptJsBoolean(horizontal)),
            "initialNumToRender": fromOption(initialNumToRender),
            "initialScrollIndex": fromOption(initialScrollIndex),
            "inverted": fromOption(UtilsRN.optBoolToOptJsBoolean(inverted)),
            "keyExtractor": keyExtractor,
            "numColumns": fromOption(numColumns),
            "onEndReached": fromOption(onEndReached),
            "onEndReachedThreshold": fromOption(onEndReachedThreshold),
            "onRefresh": fromOption(onRefresh),
            "onViewableItemsChanged": fromOption(onViewableItemsChanged),
            "overScrollMode":
              fromOption(
                UtilsRN.option_map(
                  x =>
                    switch (x) {
                    | `auto => "auto"
                    | `always => "always"
                    | `never => "never"
                    },
                  overScrollMode,
                ),
              ),
            "pagingEnabled":
              fromOption(UtilsRN.optBoolToOptJsBoolean(pagingEnabled)),
            "refreshing":
              fromOption(UtilsRN.optBoolToOptJsBoolean(refreshing)),
            "renderItem": renderItem,
            "removeClippedSubviews":
              fromOption(
                UtilsRN.optBoolToOptJsBoolean(removeClippedSubviews),
              ),
            "scrollEnabled":
              fromOption(UtilsRN.optBoolToOptJsBoolean(scrollEnabled)),
            "showsHorizontalScrollIndicator":
              fromOption(
                UtilsRN.optBoolToOptJsBoolean(showsHorizontalScrollIndicator),
              ),
            "showsVerticalScrollIndicator":
              fromOption(
                UtilsRN.optBoolToOptJsBoolean(showsVerticalScrollIndicator),
              ),
            "windowSize": fromOption(windowSize),
            "maxToRenderPerBatch": fromOption(maxToRenderPerBatch),
            "viewabilityConfig": fromOption(viewabilityConfig),
            "onScroll": fromOption(onScroll),
            "style": fromOption(style),
          }
        ),
    );
};

include CreateComponent({
  [@bs.module "react-native"]
  external view : ReasonReact.reactClass = "FlatList";
});