md temp

set tmpfile=__tmp.tmp

dir /b Character\*.bat > %tmpfile%
for /f "tokens=*" %%i in ('type %tmpfile%') do (
		call Character\%%i
	)

del %tmpfile%

pause