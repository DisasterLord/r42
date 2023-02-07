#Bilden des Arrays
class Result_BC
{
  [int] $BC_ID
  [string] $BC_Text
  [string] $BC_Benoetigt
}

class Result_WC
{
  [int] $WC_ID
  [string] $WC_Text
}

$CardsJson = "C:\Users\Fabian\Documents\GitHub\r42\Programm\CSV\cah-cards-full.json"
$BCardsCSV = "C:\Users\Fabian\Documents\GitHub\r42\Programm\CSV\B_Cards.csv"
$WCardsCSV = "C:\Users\Fabian\Documents\GitHub\r42\Programm\CSV\W_Cards.csv"

$Results_BC = @()

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
                        BC_Benoetigt = $BCard.pick 
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