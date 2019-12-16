#r "netstandard"

open System
open System.IO

Environment.CurrentDirectory <- __SOURCE_DIRECTORY__

let dir = @"../src"
let exts = ["cpp"; "hpp"]
let target = @"./include/source.satyh"

let reformPath (path : string) =
  let filename = Path.GetFileNameWithoutExtension path
  let extension = Path.GetExtension path

  (sprintf "%s%s" filename extension)
    .Replace(".", "-")
    .Replace("_", "-")

Directory.EnumerateFiles(dir)
|> Seq.filter(fun s -> exts |> Seq.exists s.EndsWith)
|> Seq.map(fun path ->
  sprintf """
let code-%s = '<+code-box(```
%s
```);>
"""
    (reformPath path)
    (File.ReadAllText path)
)
|> String.concat "\n"
|> sprintf """
@import: ./local
%s
"""
|> fun content -> File.WriteAllText(target, content)
