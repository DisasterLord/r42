#Bilden des Arrays
class Result_BC
{
  [int] $BC_ID
  [string] $BC_Text
  [int] $BC_luecken
}

class Result_WC
{
  [int] $WC_ID
  [string] $WC_Text
  [int] $WC_luecken
}

$MyDir = [System.IO.Path]::GetDirectoryName($myInvocation.MyCommand.Definition)
Set-Location $MyDir
$CardsJson = "cah-cards-full.json"
$BCardsCSV = "B_Cards.csv"
$WCardsCSV = "W_Cards.csv"

$Results_BC = @()
$Results_WC = @()
function Get-BlackCards()
{
    $ID = 1
    $FuncResults = @()


    $Cards = Get-Content -Raw $CardsJson | ConvertFrom-Json
    foreach($Card in $Cards)
    {
        $BCards =  $Card.black

        
        foreach($BCard in $BCards)
        {
            $BuildResult = $null
  
                    #Eintragen der Daten in das Array
                    $BuildResult = [Result_BC]@{
                        BC_ID = $ID
                        BC_Text = $BCard.text
                        BC_luecken = $BCard.pick 
                    }
                    $ID = $ID + 1
                    
                    $FuncResults += $BuildResult    
                }
    }
    return $FuncResults
}
function Get-WhiteCards()
{
    $ID = 1
    $FuncResults = @()


    $Cards = Get-Content -Raw $CardsJson | ConvertFrom-Json
    foreach($Card in $Cards)
    {
        $WCards =  $Card.white

        
        foreach($WCard in $WCards)
        {
            $BuildResult = $null
  
                    #Eintragen der Daten in das Array
                    $BuildResult = [Result_WC]@{
                        WC_ID = $ID
                        WC_Text = $WCard.Text
                        WC_luecken = 0
                    }
                    $ID = $ID + 1
                    
                    $FuncResults += $BuildResult    
                }
    }
    return $FuncResults
}
#Array in eine CSV-Datei Schreiben
$Results_BC += Get-BlackCards
$Results_BC | Export-Csv -LiteralPath $BCardsCSV -Delimiter ";" -NoTypeInformation
$Results_WC += Get-WhiteCards
$Results_WC | Export-Csv -LiteralPath $WCardsCSV -Delimiter ";" -NoTypeInformation