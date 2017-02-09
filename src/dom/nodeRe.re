type t = DomRe.node;

type nodeType =
| Element
| Attribute /* deprecated */
| Text
| CDATASection /* deprecated */
| EntityReference /* deprecated */
| Entity /* deprecated */
| ProcessingInstruction
| Comment
| Document
| DocumentType
| DocumentFragment
| Notation /* deprecated */
| Unknown;
let decodeNodeType = fun /* internal */
|  1 => Element
|  2 => Attribute
|  3 => Text
|  4 => CDATASection
|  5 => EntityReference
|  6 => Entity
|  7 => ProcessingInstruction
|  8 => Comment
|  9 => Document
| 10 => DocumentType
| 11 => DocumentFragment
| 12 => Notation
|  _ => Unknown;

/* baseURI */
external childNodes : t => DomRe.nodeList  = "" [@@bs.get];
external firstChild : t => Js.null t = "" [@@bs.get];
let firstChild : t => option t = fun self => Js.Null.to_opt (firstChild self);
external innerText : t => string = "" [@@bs.get];
external setInnerText : t => string => unit = "innerText" [@@bs.set];
external lastChild : t => Js.null t = "" [@@bs.get];
let lastChild : t => option t = fun self => Js.Null.to_opt (lastChild self);
external nextSibling : t => Js.null t = "" [@@bs.get];
let nextSibling : t => option t = fun self => Js.Null.to_opt (nextSibling self);
external nodeName : t => string = "" [@@bs.get];
/* nodePrincipal */
external nodeType : t => int /* nodeType enum */ = "" [@@bs.get];
let nodeType : t => nodeType = fun self => decodeNodeType (nodeType self);
external nodeValue : t => Js.null string = "" [@@bs.get];
let nodeValue : t => option string = fun self => Js.Null.to_opt (nodeValue self);
external setNodeValue : t => Js.null string => unit = "nodeValue" [@@bs.set];
let setNodeValue : t => option string => unit = fun self value => setNodeValue self (Js.Null.from_opt value);
/* outerText */
external ownerDocument : t => DomRe.document = "" [@@bs.get];
external parentElement : t => Js.null DomRe.element = "" [@@bs.get];
let parentElement : t => option DomRe.element = fun self => Js.Null.to_opt (parentElement self);
external parentNode : t => Js.null t = "" [@@bs.get];
let parentNode : t => option t = fun self => Js.Null.to_opt (parentNode self);
external previousSibling : t => Js.null t = "" [@@bs.get];
let previousSibling : t => option t = fun self => Js.Null.to_opt (previousSibling self);
external rootNode : t => t = "" [@@bs.get];
external textContent : t => string = "" [@@bs.get];
external setTextContent : t => string => unit = "textContent" [@@bs.set];

external appendChild : t => unit = "" [@@bs.send.pipe: t];
external cloneNode : t = "" [@@bs.send.pipe: t];
external cloneNodeDeep : Js.boolean => t = "cloneNode" [@@bs.send.pipe: t];
let cloneNodeDeep : t => t = fun self => cloneNodeDeep (Js.Boolean.to_js_boolean true) self;
external compareDocumentPosition : t => int = "" [@@bs.send.pipe: t]; /* returns a bitmask which could also be represeneted as an enum, see https://developer.mozilla.org/en-US/docs/Web/API/Node/compareDocumentPosition */
external contains : t => Js.boolean = "" [@@bs.send.pipe: t];
let contains : t => t => bool = fun node self => Js.to_bool (contains node self);
external getRootNode : t = "" [@@bs.send.pipe: t];
external getRootNodeComposed : Js.boolean => t = "getRootNode" [@@bs.send.pipe: t];
let getRootNodeComposed : t => t = fun self => getRootNodeComposed (Js.Boolean.to_js_boolean true) self;
external hasChildNodes : Js.boolean = "" [@@bs.send.pipe: t];
let hasChildNodes : t => bool = fun self => Js.to_bool (hasChildNodes self);
external insertBefore : t => Js.null t => t = "" [@@bs.send.pipe: t];
let insertBefore : t => option t => t => t = fun node reference self => insertBefore node (Js.Null.from_opt reference) self;
external isDefaultNamespace : string => Js.boolean = "" [@@bs.send.pipe: t];
let isDefaultNamespace : string => t => bool = fun ns self => Js.to_bool (isDefaultNamespace ns self);
external isEqualNode : t => Js.boolean = "" [@@bs.send.pipe: t];
let isEqualNode: t => t => bool = fun node self => Js.to_bool (isEqualNode node self);
external isSameNode : t => Js.boolean = "" [@@bs.send.pipe: t];
let isSameNode: t => t => bool = fun node self => Js.to_bool (isSameNode node self);
external lookupNamespaceURI : Js.null string => Js.null string = "" [@@bs.send.pipe: t];
let lookupNamespaceURI: option string => t => option string = fun prefix self => Js.Null.to_opt (lookupNamespaceURI (Js.Null.from_opt prefix) self);
external lookupPrefix : string = "lookupPrefix" [@@bs.send.pipe: t];
external normalize : unit = "" [@@bs.send.pipe: t];
external removeChild : t => t = "" [@@bs.send.pipe: t];
/* replacChild */