
Enable-PSRemoting

$sess = New-PSSession -ComputerName <Name>
Enter-PSSession -ComputerName <Name> OR -Sessions <SessionName>

$SecPassword = ConvertTo-SecureString '<Wtver>' -AsPlainText -Force
$Cred = New-Object System.Management.Automation.PSCredential('htb.local\<WtverUser>', $SecPassword)
Invoke-Command -ComputerName <WtverMachine> -Credential $Cred -ScriptBlock {whoami}


Invoke-Command -Credential $cred -ComputerName <NameOfComputer> -FilePath c:\FilePath\file.ps1 -Session $sess


Enter-PSSession -Session $sess


$sess = New-PSSession -ComputerName <NameOfComputer>


Invoke-Command -Session $sess -ScriptBlock {$ps = Get-Process}


Invoke-Command -Session $sess -ScriptBlock {$ps}

reg query HKLM\SYSTEM\CurrentControlSet\Control\Lsa