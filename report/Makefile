build/report-ivip.pdf: ./*.saty ./include/*.satyh
	satysfi report.saty -o build/report-ivip.pdf

include/source.satyh: ../src/**.*pp ./pack.fsx
	dotnet fsi --exec pack.fsx
