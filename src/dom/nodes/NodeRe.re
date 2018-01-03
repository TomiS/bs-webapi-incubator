module Impl = (T: {type t;}) => {
  /* baseURI */
  [@bs.get] external childNodes : T.t => Dom.nodeList = "";
  [@bs.get] [@bs.return null_to_opt] external firstChild : T.t => option(Dom.node) = "";
  [@bs.get] external innerText : T.t => string = "";
  [@bs.set] external setInnerText : (T.t, string) => unit = "innerText";
  [@bs.get] [@bs.return nullable] external lastChild : T.t => option(Dom.node) = "";
  [@bs.get] [@bs.return null_to_opt] external nextSibling : T.t => option(Dom.node) = "";
  [@bs.get] external nodeName : T.t => string = ""; /* nodePrincipal */
  [@bs.get] external nodeType : T.t => int /* nodeType enum */ = "";
  let nodeType: T.t => DomTypesRe.nodeType = (self) => DomTypesRe.decodeNodeType(nodeType(self));
  [@bs.get] [@bs.return null_to_opt] external nodeValue : T.t => option(string) = "";
  [@bs.set] external setNodeValue : (T.t, Js.null(string)) => unit = "nodeValue";
  /* let setNodeValue : T.t => option string => unit = fun self value => setNodeValue self (Js.Null.from_opt value); */ /* temporarily removed to reduce codegen size */
  /* Not supported yet
  external setNodeValue : T.t => string => unit = "nodeValue" [@@bs.set];
  external clearNodeValue : T.t => _ [@bs.as {json|null|json}] => unit = "nodeValue" [@@bs.set];
  */
  /* outerText */
  [@bs.get] external ownerDocument : T.t => Dom.document = "";
  [@bs.get] [@bs.return null_to_opt] external parentElement : T.t => option(Dom.element) = "";
  [@bs.get] [@bs.return null_to_opt] external parentNode : T.t => option(Dom.node) = "";
  [@bs.get] [@bs.return null_to_opt] external previousSibling : T.t => option(Dom.node) = "";
  [@bs.get] external rootNode : T.t => Dom.node = "";
  [@bs.get] external textContent : T.t => string = "";
  [@bs.set] external setTextContent : (T.t, string) => unit = "textContent";

  [@bs.send.pipe : T.t] external appendChild : Dom.node_like('a) => unit = "";
  [@bs.send.pipe : T.t] external cloneNode : Dom.node = "";
  [@bs.send.pipe : T.t] external cloneNodeDeep : ([@bs.as {json|true|json}] _) => Dom.node = "cloneNode";
  [@bs.send.pipe : T.t] external compareDocumentPosition : Dom.node_like('a) => int = ""; /* returns a bitmask which could also be represeneted as an enum, see https://developer.mozilla.org/en-US/docs/Web/API/Node/compareDocumentPosition */
  [@bs.send.pipe : T.t] external contains : Dom.node_like('a) => bool = "";
  [@bs.send.pipe : T.t] external getRootNode : Dom.node = "";
  [@bs.send.pipe : T.t] external getRootNodeComposed : ([@bs.as {json|{ "composed": true }|json}] _) => Dom.node = "getRootNode";
  [@bs.send.pipe : T.t] external hasChildNodes : bool = "";
  [@bs.send.pipe : T.t] external insertBefore : (Dom.node_like('a), Dom.node_like('b)) => Dom.node_like('a) = "";
  /* (temporarily?) removed to reduce codegen size. This variant is just for convenience, `appendChild` can be used in place of passing `null` to `insertBefore`
  external insertBefore : Dom.node_like 'a => Js.null (Dom.node_like 'b) => Dom.node_like 'a = "" [@@bs.send.pipe: T.t];
  let insertBefore : Dom.node_like 'a => option (Dom.node_like 'b) => T.t => Dom.node_like 'a = fun node reference self => insertBefore node (Js.Null.from_opt reference) self;
  */
  [@bs.send.pipe : T.t] external isDefaultNamespace : string => bool = "";
  [@bs.send.pipe : T.t] external isEqualNode : Dom.node_like('a) => bool = "";
  [@bs.send.pipe : T.t] external isSameNode : Dom.node_like('a) => bool = "";
  [@bs.send.pipe : T.t] [@bs.return null_to_opt] external lookupNamespaceURI : string => option(string) = "";
  [@bs.send.pipe : T.t] [@bs.return null_to_opt] external lookupDefaultNamespaceURI : ([@bs.as {json|null|json}] _) => option(string) = "lookupNamespaceURI";
  [@bs.send.pipe : T.t] external lookupPrefix : string = "lookupPrefix";
  [@bs.send.pipe : T.t] external normalize : unit = "";
  [@bs.send.pipe : T.t] external removeChild : Dom.node_like('a) => Dom.node_like('a) = "";
  /* replacChild */
};

type t = Dom.node;

include EventTargetRe.Impl({ type nonrec t = t; });
include Impl({ type nonrec t = t; });
