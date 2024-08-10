@echo off

cd /d %USERPROFILE%\AppData\Local\DayZ
del *.log *.RPT *.mdmp /q /s

start /d "D:\SteamLibrary\steamapps\common\DayZ" DayZDiag_x64.exe -mod=P:\Builds\@EventsAPI;D:\SteamLibrary\steamapps\common\DayZ\!Workshop\@ZomBerry Admin Tools;D:\SteamLibrary\steamapps\common\DayZ\!Workshop\@CF -mission=D:\SteamLibrary\steamapps\common\DayZ\Missions\dayzOffline.ChernarusPlus -window -filePatching