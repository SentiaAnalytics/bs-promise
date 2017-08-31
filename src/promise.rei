type t 'err 'a;
let resolve : 'a =>  t 'x 'a;
let reject : 'err =>  t 'err 'a;
let all : list (t 'err 'a) => t 'err (list 'a);
let map: ('a => 'b) => t 'x 'a => t 'x 'b;
let chain: ('a => t 'x 'b) => t 'x 'a => t 'x 'b;

let catch : ('x => 'a) => t 'x 'a => t 'x 'a;

let biMap: ('x => 'y) => ('a => 'b) => t 'x 'a => t 'y 'b;

let mapError : ('x => 'y) => t 'x 'a => t 'y 'a;

let finally : ('x => unit) => ('a => unit) => t 'x 'a => unit;

let fold : ('x => 'b) => ('a => 'b) => t 'x 'a => t 'x 'b;

let fromOption : 'x => option 'a => t 'x 'a;

let fromJs : Js.Promise.t 'a => t 'x 'a; 

let make : (('x => unit) => ('a => unit) => unit) => t 'x 'a;