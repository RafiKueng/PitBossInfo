PitBossInfo
===========

a Win32 tool for Sid Meyers Civilisation 4 BtS PitBoss server administrators and their players.
Generates an overview of
* all the players
* their points
* whether they did their turn
* finishing time of the actual round.

Specs:
------
* written in pure c++, no .NET or any fancy libs needed
* (more or less) leigthweigth win32 console app (~200k)
* unicode compatible (but pitboss itself isn't...)
* using winapi functions to read out infos from pitbos window (even if it's minimized)
* generates html and txt
* expandable by (hardcoded) plugins to write your own output
* supports multiple servers (ussing multiple instances, with commandline switches)

required commandline switches:
------------------------------
- `-p` output path and filename, without extension
- `-t` refresh timer in sec
- `-l` language of pitboss (NOT yet supported, please use default english)
- `-n` name of the game (exactly as displayed in the pitboss window)

===example:
`*PitBossInfo.exe -p "D:/htdocs/game1" -t 15 -l en -n "MyFirstGame"*`
this creates the output in `D:/htdocs` named `game1.html` and `game1.txt` for the game named "MyFirstGame" (the title of the pitboss window is "MyFirstGame successfully saved")

Version / History / Features
-----------------
===v1.1:
* `(main)` removed hardcoded settings and replaced by command line arguments [rafik]

===RC4:
* `(html)` added sortable table header [rafik]

===RC3:
* `(html)` stylesheet for html output [bdurrer]
* `(html)` automatic update of html page every 2 min [rafik]

===RC2:
* `(main)` added simple html output [bdurrer+rafik]
* `(main)` added timestamp of last update of stats [bdurrer+rafik]

===RC1:
* `(main)` made all the internal things working [rafik]
* `(main)` creates simple txt output [rafik]

Planned features
----------
The following features are planned and could be added somewhen
* `(main)` xmpp output to webapp by [bdurrer] for (mobile) apps
* `(apps)` andoid and iphone apps (or maybe not)
* `(main)` log state changes by events and output them (status_change [login, logout, claim_ai, become_ai, defeated], points_change, name_change)
