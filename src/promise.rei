type t 'err 'a;
let resolve : 'a =>  t 'x 'a; /* Create a resolved promise */

let reject : 'err =>  t 'err 'a; /* Create a rejected Promise */

let all : list (t 'err 'a) => t 'err (list 'a); /* Turn a list of promises into a promise of a list */

let map: ('a => 'b) => t 'x 'a => t 'x 'b;

let chain: ('a => t 'x 'b) => t 'x 'a => t 'x 'b;

let bind: ('a => t 'x 'b) => t 'x 'a => t 'x 'b; /* alias for chain */


let biMap: ('x => 'y) => ('a => 'b) => t 'x 'a => t 'y 'b; /* map either the error or the value of a promise */

let mapError : ('x => 'y) => t 'x 'a => t 'y 'a; /* apply a function to a rejected promise */

let catch : ('x => 'a) => t 'x 'a => t 'x 'a; /* Similar to mapError but returns a resolved promise */

/* Provide handlers for the error and result option of the promise. Use this as the last step in a promise chain. */
let finally : ('x => unit) => ('a => unit) => t 'x 'a => unit; 

let fold : ('x => 'b) => ('a => 'b) => t 'x 'a => t 'x 'b; /* Acts as both map and catch*/

let fromOption : 'x => option 'a => t 'x 'a; /* return a promise from an option type */

let fromJs : Js.Promise.t 'a => t 'x 'a; /* return a Promise.t from a Js.Promise.t */

let make : (('x => unit) => ('a => unit) => unit) => t 'x 'a; 
/* 
returns a new promise that will be resolved when the resolve function is called,  or rejected when the reject function is called
*/