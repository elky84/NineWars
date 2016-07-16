set tmpfile=__tmp.tmp

dir /b Effect\*.bat > %tmpfile%
for /f "tokens=*" %%i in ('type %tmpfile%') do (
		call Effect\%%i
	)

del %tmpfile%

pause