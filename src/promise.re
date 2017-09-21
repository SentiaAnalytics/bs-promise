type t 'err 'a;

external _new : (('a => unit) => ('x => unit) => unit) => t 'x 'a = "Promise" [@@bs.new];
external _map : t 'x 'a => ('a => 'b) => t 'x 'b = "then" [@@bs.send];
external _chain : t 'x 'a => ('a => t 'x 'b) => t 'x 'b = "then" [@@bs.send];
external _fold : t 'x 'a => ('a => 'b) => ('x => 'b) => t 'x 'b = "then" [@@bs.send];
external _then : t 'x 'a => ('a => 'b) => ('x => t 'y 'b) => t 'y 'b = "then" [@@bs.send];
external _finally : t 'x 'a => ('a => unit) => ('x => unit) => t unit unit = "then" [@@bs.send];
external _catch : t 'x 'a => ('x => t 'y 'b) => t 'x 'a = "catch" [@@bs.send];
external _end : t unit unit => (unit => unit) => unit = "catch" [@@bs.send];
external resolve : 'a =>  t 'x 'a = "resolve" [@@bs.val] [@@bs.scope "Promise"];
external reject : 'err =>  t 'err 'a = "reject" [@@bs.val] [@@bs.scope "Promise"];
external all : list (t 'err 'a) => t 'err (list 'a) = "all" [@@bs.val] [@@bs.scope "Promise"];
external _fromjs : Js.Promise.t 'a => ('a => 'a) => t 'x 'a = "then" [@@bs.send];
let map f p => _map p f;
let chain f p => _chain p f;
let bind = chain;
let catch f p => _catch p (fun x => reject (f x));

let biMap fail success p => _then p success (fun err => reject (fail err));

let mapError f p => _then p (fun x => x) (fun err => reject (f err));

let finally f g p => _finally p g f |> (fun p => _end p (fun () => ()));

let fold f g p => _fold p g f;

let fromOption err opt => switch opt {
| None => reject err
| Some a => resolve a 
};


let fromJs p => _fromjs p (fun x => x);

let make f => _new (fun resolve reject => f reject resolve);


