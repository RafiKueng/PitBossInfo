PitBossInfo
===========

a Win32 tool for Sid Meyers Civilization 4 BtS PitBoss server administrators and their players.
Generates an overview of
* all the players
* their points
* whether they did their turn
* finishing time of the actual round.

Specs:
------
* written in pure c++, no .NET or any fancy libs needed
* (more or less) lightweight win32 console app (~200k)
* Unicode compatible (but PitBoss itself isn't...)
* using winapi functions to read out infos from PitBoss window (even if it's minimized)
* generates `.html` and `.txt`
* expandable by (hard coded) plug ins to write your own output
* supports multiple servers (using multiple instances, with command line switches)

(Required) Command line Switches:
------------------------------
- `-p` output path and file name, without extension
- `-t` refresh timer in sec
- `-l` language of PitBoss (NOT yet supported, please set PitBoss to default English; in `CivilisationIV.ini` set `Language = 0`)
- `-n` name of the game (exactly as displayed in the PitBoss window)

###example:
`*PitBossInfo.exe -p "D:/htdocs/game1" -t 15 -l en -n "MyFirstGame"*`
this creates the output in `D:/htdocs` named `game1.html` and `game1.txt` for the game named "MyFirstGame" (the title of the pitboss window is "MyFirstGame successfully saved")

Version / History / Features
-----------------
###v1.1:
* `(main)` removed hard coded settings and replaced by command line arguments [rafik]

###RC4:
* `(html)` added sortable table header [rafik]
* `(main)` bugfixes: "\*MOD\*"-issue; "defeated, "-issue

###RC3:
* `(html)` stylesheet for html output [bdurrer]
* `(html)` automatic update of html page every 2 min [rafik]
* `(html)` w3c valid html + css

###RC2:
* `(main)` added simple html output [bdurrer+rafik]
* `(main)` added time stamp of last update of stats [bdurrer+rafik]

###RC1:
* `(main)` made all the internal things working [rafik]
* `(main)` fixed memory leaks
* `(main)` creates simple txt output [rafik]

Planned features
----------
The following features are planned and could be added some when
* `(main)` xmpp output to webapp by [bdurrer] for (mobile) apps
* `(apps)` android and iphone apps (or maybe not)
* `(main)` log state changes by events and output them (status_change [login, logout, claim_ai, become_ai, defeated], points_change, name_change)
