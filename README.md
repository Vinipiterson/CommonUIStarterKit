# Common UI Starter Kit

Setting Up:
- In ProjectSettings, Replace LocalPlayerClass and GameViewportClientClass with the CommonUI version.
  ![image](https://github.com/user-attachments/assets/34eccf77-508e-46e4-9595-76085c3f2530)
  
  ![image](https://github.com/user-attachments/assets/868536d8-42c3-4f10-b122-4933bb9185ee)

- Create a game instance based on CommonGameInstance and set it on project settings.
- Add ```[/Script/CommonUIStarterKit.UISKGameUIManagerSubsystem]
DefaultUIPolicyClass=/CommonUIStarterKit/B_SK_GameUIPolicy.B_SK_GameUIPolicy_C``` to DefaultGame.ini

Use push content to layer for player to add a widget to the viewport, don`t use CreateWidget.
