# Common UI Starter Kit

Basic CommonUI knowledge required.

## Setting Up

1. **Replace LocalPlayer and GameViewportClient**

   * In **Project Settings**, under **Maps & Modes**, set **Local Player Class** and **GameViewport Client Class** to the CommonUI versions:

     ![LocalPlayerClass](https://github.com/user-attachments/assets/34eccf77-508e-46e4-9595-76085c3f2530)
     ![GameViewportClientClass](https://github.com/user-attachments/assets/868536d8-42c3-4f10-b122-4933bb9185ee)

2. **Game Instance**

   * Create a subclass of `CommonGameInstance` and assign it in **Project Settings** → **Engine** → **General Settings** → **Game Instance Class**.

3. **DefaultGame.ini Configuration**
   Add the following section to your **DefaultGame.ini**:

   ```ini
   [/Script/CommonUIStarterKit.UISKGameUIManagerSubsystem]
   DefaultUIPolicyClass=/CommonUIStarterKit/Blueprints/UI/B_SK_GameUIPolicy.B_SK_GameUIPolicy_C
   ```

---

## Creating a Widget

When building main UI elements (e.g., main menu, settings, pause menu, in‑game overlay), always inherit from **`UISKCommonActivatableWidget`**. This base class provides built‑in handling for input and activation behavior.

* **Input Config**:

  * **Game**: Player input affects the game only.
  * **Game + Menu**: Input interacts with both UI and game.
  * **Menu**: UI handles all input.

* **Game Mouse Capture Mode**:

  * **No Capture**: All mouse input goes to the widget.
  * **Capture Permanently**: Game handles all input.
  * **Capture During Mouse Down**: Game processes input when clicking on the game screen.

---

## Using Widgets

* **Add a widget**: Call **`Push Content To Layer For Player`** with the following parameters:

  * **Player Controller**
  * **Widget Instance**
  * **UI Layer**:

    * `Game` (e.g., HUD: health bar, minimap)
    * `Game Menu` (e.g., shop, inventory)
    * `Menu` (e.g., main menu, pause)
    * `Modal` (e.g., confirmation pop-ups)

* **Remove a widget**: From C++, call **`Deactivate`** on the `UISKCommonActivatableWidget`.

---

## Binding Input to Action Bar

`UISKCommonActivatableWidget` also supports binding input actions directly:

* **Register a binding**:

  * Use **`Register Binding`**, passing an **InputAction** and callback delegate.

* **Unregister a binding**:

  * Use **`Unregister Binding`**, passing the binding handle you received.
 
* **Unregister all bindings**:

  * Use **`Unregister all Bindings`** to unregister all actions registered in that widget.
