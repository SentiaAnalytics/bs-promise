open Tape;

test "resolve should return a resolved promise" (fun t => {
  t.plan 1;
  Promise.resolve 5 |> Promise.finally 
    (fun () => ())
    (fun x => t.ok (x == 5));
}); 

test "reject should return a rejected promise" (fun t => {
  t.plan 1;
  Promise.reject "rejected" |> Promise.finally 
    (fun x => t.ok (x == "rejected"))
    (fun _ => ());
}); 

test "map should map the resolved value" (fun t => {
  t.plan 1;
  Promise.resolve 1 
    |> Promise.map (fun x => x + 1)
    |> Promise.finally (fun _ => ()) (fun x => t.ok (x == 2));
});

test "chain should chain the resolved value" (fun t => {
  t.plan 1;
  Promise.resolve 1 
    |> Promise.chain (fun x => Promise.resolve (x + 1))
    |> Promise.finally (fun _ => ()) (fun x => t.ok (x == 2));
});

test "fold should map a resolved promise over the second function" (fun t => {
 t.plan 1; 
 Promise.resolve 1
  |> Promise.fold (fun a => a) (fun n => n + 1)
  |> Promise.finally (fun _ => ()) (fun n => t.ok (n == 2));
});

test "fold should return a resolved promise from a rejected promise" (fun t => {
 t.plan 1; 
 Promise.reject "Err"
  |> Promise.fold (fun _ => "Success") (fun a => a)
  |> Promise.finally (fun _ => ()) (fun x => t.ok (x == "Success"));
});


test "make should create a new Promise" (fun t => {
  t.plan 1;
  Promise.make (fun _ resolve => { resolve 5; })
  |> Promise.finally (fun _ => ()) (fun x => t.ok message::{j|Promise should be 5|j} (x == 5));
});