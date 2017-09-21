# bs-promise

promise library for Ocaml/Reason based on javascript promises.

example:

```js
Promise.make (fun reject resolve  => resolve "Hello")
  |> Promise.map (fun s => s ^ ", World!")
  |> Promise.finally (fun err => print_endline @@ "Error: " ^ err) (fun s => print_endline s );
```

Read the [promise.rei](/src/Promise.rei) file for the api.