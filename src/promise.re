type t 'err 'a;

external _map : t 'x 'a => ('a => 'b) => t 'x 'b = "then" [@@bs.send];
external _chain : t 'x 'a => ('a => t 'x 'b) => t 'x 'b = "then" [@@bs.send];
external _fold : t 'x 'a => ('a => 'b) => ('x => 'b) => t 'x 'b = "then" [@@bs.send];
external _biMap : t 'x 'a => ('a => 'b) => ('x => 'y) => t 'y 'b = "then" [@@bs.send];
external _finally : t 'x 'a => ('a => unit) => ('x => unit) => unit = "then" [@@bs.send];
external _catch : t 'x 'a => ('x => t 'y 'b) => t 'x 'a = "catch" [@@bs.send];
external resolve : 'a =>  t 'x 'a = "resolve" [@@bs.val] [@@bs.scope "Promise"];
external reject : 'err =>  t 'err 'a = "reject" [@@bs.val] [@@bs.scope "Promise"];
external all : list (t 'err 'a) => t 'err (list 'a) = "all" [@@bs.val] [@@bs.scope "Promise"];
let map f p => _map p f;
let chain f p => _chain p f;
let catch f p => _catch p (fun x => reject (f x));

let biMap fail success p => _biMap p success fail;

let mapError f p => _biMap p (fun x => x) f;

let finally f g p => _finally p g f;

let fold f g p => _fold p g f;

let fromOption err opt => switch opt {
| None => reject err
| Some a => resolve a
};

