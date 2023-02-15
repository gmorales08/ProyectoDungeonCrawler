@echo off
:: chcp 65001 habilita la impresion de caracteres utf-8
chcp 65001
:: el siguiente comando agrega al regedit la entrada VirtualTerminalLevel
:: para poder imprimir caracteres ANSI en el cmd de Windows
HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 1
title DungeonCrawler
mode con: cols=80 lines=24
cls
cd win64
pdg
pause

