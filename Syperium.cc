--// Integrated Syperium Key System
local CorrectKey = "XvR0zLp88Wq22nNbBvVmMpPqQwWeErRtTyY"
local KeyLink = "https://discord.gg/syperium"
local KeyVerified = false

--// Services
local Services = setmetatable({}, {
    __index = function(self, Name)
        return game:GetService(Name)
    end,
})

local TweenService = Services.TweenService
local Players = Services.Players
local RunService = Services.RunService
local Workspace = Services.Workspace
local UserInputService = Services.UserInputService
local Stats = Services.Stats
local Lighting = Services.Lighting
local TeleportService = game:GetService("TeleportService")
local ContextActionService = game:GetService("ContextActionService")
local VirtualInputManager = game:GetService("VirtualInputManager")

local CoreGui = game:GetService("CoreGui")
local LocalPlayer = Players.LocalPlayer
local Camera = Workspace.CurrentCamera

local library_colors = {
    backgroundColor = Color3.fromRGB(31, 31, 31),
    acientColor = Color3.fromRGB(10,30,61),
    companyColor = Color3.fromRGB(163, 151, 255),
    lightGray = Color3.fromRGB(48, 48, 48),
    Font = Enum.Font.Code,
    rainbowColors = ColorSequence.new{
        ColorSequenceKeypoint.new(0.00, Color3.fromRGB(241, 137, 53)),
        ColorSequenceKeypoint.new(0.33, Color3.fromRGB(241, 53, 106)),
        ColorSequenceKeypoint.new(0.66, Color3.fromRGB(133, 53, 241)),
        ColorSequenceKeypoint.new(1, Color3.fromRGB(53, 186, 241))
    }
}

--// Clipboard
local function SetClipboard(input)
    local clipBoard = setclipboard or toclipboard or set_clipboard or (Clipboard and Clipboard.set)
    if clipBoard then clipBoard(input) end
end

local function LaunchKeySystem()
    local screen = Instance.new("ScreenGui", CoreGui)
    screen.Name = "SyperiumAuth"
   
    local background = Instance.new("Frame", screen)
    background.AnchorPoint = Vector2.new(0.5, 0.5)
    background.BackgroundColor3 = library_colors.backgroundColor
    background.Position = UDim2.new(0.5, 0, 0.5, 0)
    background.Size = UDim2.fromOffset(350, 200)
    background.BorderSizePixel = 0
   
    local BGStroke = Instance.new("UIStroke", background)
    BGStroke.Color = Color3.fromRGB(26, 26, 26)
    BGStroke.Thickness = 2
    BGStroke.Transparency = 0.4
   
    local BGGradient = Instance.new("UIGradient", background)
    BGGradient.Color = ColorSequence.new{
        ColorSequenceKeypoint.new(0.00, Color3.fromRGB(34, 34, 34)),
        ColorSequenceKeypoint.new(1.00, Color3.fromRGB(28, 28, 28))
    }
    BGGradient.Rotation = 90
   
    local BGCorner = Instance.new("UICorner", background)
    BGCorner.CornerRadius = UDim.new(0, 4)
   
    local bar = Instance.new("Frame", background)
    bar.Size = UDim2.new(1, 0, 0, 2)
    bar.BorderSizePixel = 0
   
    local barGradient = Instance.new("UIGradient", bar)
    barGradient.Color = library_colors.rainbowColors
   
    task.spawn(function()
        while true do
            barGradient.Offset = Vector2.new(-1, 0)
            local t = TweenService:Create(barGradient, TweenInfo.new(3, Enum.EasingStyle.Linear), {Offset = Vector2.new(1, 0)})
            t:Play()
            t.Completed:Wait()
        end
    end)
   
    local title = Instance.new("TextLabel", background)
    title.Size = UDim2.new(1, 0, 0, 40)
    title.Position = UDim2.new(0, 15, 0, 10)
    title.BackgroundTransparency = 1
    title.Font = library_colors.Font
    title.Text = "SYPERIUM <font color='rgb(163, 151, 255)'>AUTHENTICATION</font>"
    title.RichText = true
    title.TextColor3 = Color3.fromRGB(198, 198, 198)
    title.TextSize = 16
    title.TextXAlignment = Enum.TextXAlignment.Left
   
    local textBox = Instance.new("TextBox", background)
    textBox.Size = UDim2.new(0, 320, 0, 35)
    textBox.Position = UDim2.new(0.5, -160, 0.45, 0)
    textBox.BackgroundColor3 = Color3.fromRGB(27, 27, 27)
    textBox.Font = library_colors.Font
    textBox.PlaceholderText = "Paste key here..."
    textBox.Text = ""
    textBox.TextColor3 = Color3.new(1, 1, 1)
    textBox.TextSize = 14
    Instance.new("UICorner", textBox)
    local boxStroke = Instance.new("UIStroke", textBox)
    boxStroke.Color = library_colors.lightGray
   
    local buttonContainer = Instance.new("Frame", background)
    buttonContainer.BackgroundTransparency = 1
    buttonContainer.Position = UDim2.new(0.5, -160, 0.72, 0)
    buttonContainer.Size = UDim2.new(0, 320, 0, 35)
   
    local layout = Instance.new("UIListLayout", buttonContainer)
    layout.FillDirection = Enum.FillDirection.Horizontal
    layout.HorizontalAlignment = Enum.HorizontalAlignment.Center
    layout.Padding = UDim.new(0, 10)
   
    local submit = Instance.new("TextButton", buttonContainer)
    submit.Size = UDim2.new(0, 155, 1, 0)
    submit.BackgroundColor3 = Color3.fromRGB(35, 35, 35)
    submit.Font = library_colors.Font
    submit.Text = "ACCESS"
    submit.TextColor3 = library_colors.companyColor
    submit.TextSize = 14
    Instance.new("UICorner", submit).CornerRadius = UDim.new(0, 4)
    local btnStroke = Instance.new("UIStroke", submit)
    btnStroke.Color = library_colors.companyColor
    btnStroke.ApplyStrokeMode = Enum.ApplyStrokeMode.Border
   
    local getKey = Instance.new("TextButton", buttonContainer)
    getKey.Size = UDim2.new(0, 155, 1, 0)
    getKey.BackgroundColor3 = Color3.fromRGB(35, 35, 35)
    getKey.Font = library_colors.Font
    getKey.Text = "GET KEY"
    getKey.TextColor3 = Color3.fromRGB(198, 198, 198)
    getKey.TextSize = 14
    Instance.new("UICorner", getKey).CornerRadius = UDim.new(0, 4)
    local getStroke = Instance.new("UIStroke", getKey)
    getStroke.Color = library_colors.lightGray
    getStroke.ApplyStrokeMode = Enum.ApplyStrokeMode.Border
   
    submit.MouseButton1Click:Connect(function()
        if textBox.Text == CorrectKey then
            KeyVerified = true
            TweenService:Create(background, TweenInfo.new(0.5, Enum.EasingStyle.Quad, Enum.EasingDirection.In), {Position = UDim2.new(0.5, 0, 1.5, 0)}):Play()
            task.wait(0.5)
            screen:Destroy()
        else
            textBox.Text = ""
            textBox.PlaceholderText = "INVALID KEY"
            btnStroke.Color = Color3.fromRGB(255, 74, 77)
            task.wait(1)
            btnStroke.Color = library_colors.companyColor
            textBox.PlaceholderText = "Paste key here..."
        end
    end)
   
    getKey.MouseButton1Click:Connect(function()
        SetClipboard(KeyLink)
        local oldText = getKey.Text
        getKey.Text = "COPIED!"
        getStroke.Color = library_colors.companyColor
        task.wait(2)
        getKey.Text = oldText
        getStroke.Color = library_colors.lightGray
    end)
   
    repeat task.wait() until KeyVerified
end

LaunchKeySystem()

--------------------------------------------------------------------------------
-- SYPERIUM ULTIMATE | CORE
--------------------------------------------------------------------------------
local library = loadstring(game:HttpGet("https://raw.githubusercontent.com/L3nzo/SyperiumUiLib/refs/heads/main/SyperiumLib"))()
library.headerColor = Color3.fromRGB(51, 158, 190)
library.companyColor = Color3.fromRGB(163, 151, 255)
library.acientColor = Color3.fromRGB(159, 115, 255)

local MainKeybind = Enum.KeyCode.RightShift

ContextActionService:BindActionAtPriority("SyperiumIntroLock", function()
    return Enum.ContextActionResult.Sink
end, false, 2000, MainKeybind)

library:Init({
    version = "Syperium | Private",
    title = "Private",
    company = "Syperium",
    keybind = MainKeybind,
    BlurEffect = true
})

local Config = {
    AimbotEnabled = false,
    AimbotKey = Enum.KeyCode.E,
    AimPart = "Head",
    AimSmoothing = 5,
    AimFOVEnabled = false,
    AimFOVSize = 100,
    HitboxExpander = false,
    HitboxSize = 15,
    HitboxTransparency = 0.5,
    PlayerESP = false,
    BoxESP = false,
    NameESP = false,
    DistanceESP = false,
    ToolESP = false,
    HealthBar = false,
    StatusESP = false,
    RenderDistance = 2000,
    CrateESP = false,
    CrateName = true,
    CrateHighlight = false,
    CrateRarities = {["1"]=true,["2"]=true,["3"]=true,["4"]=true,["5"]=true,["6"]=true},
    AutoFarm = false,
    WalkSpeedEnabled = false,
    WalkSpeedActive = false,
    WalkSpeedValue = 16,
    WalkSpeedKey = Enum.KeyCode.X,
    ZoomEnabled = false,
    ZoomKey = Enum.KeyCode.V,
    ZoomFOV = 30,
    CustomFOVEnabled = false,
    CustomFOVValue = 70,
    IsZooming = false,
    KeybindListEnabled = true
}

-- Create Keybind HUD
local KeybindHUD = library:CreateKeybindHUD()

-- Override the internal update to make it more reliable with your Config
-- (This fixes the main issue)
local function ForceUpdateKeybindHUD()
    if KeybindHUD.Update then
        KeybindHUD:Update()
    end
end

local RarityData = {
    ["1"] = {Name = "Common", Color = Color3.fromRGB(170,170,170)},
    ["2"] = {Name = "Uncommon", Color = Color3.fromRGB(85,255,127)},
    ["3"] = {Name = "Rare", Color = Color3.fromRGB(85,170,255)},
    ["4"] = {Name = "Epic", Color = Color3.fromRGB(170, 85,255)},
    ["5"] = {Name = "Legendary", Color = Color3.fromRGB(255,255, 0)},
    ["6"] = {Name = "Mythic", Color = Color3.fromRGB(255, 0, 0)}
}

local function updateFOV()
    if Config.IsZooming and Config.ZoomEnabled then
        Camera.FieldOfView = Config.ZoomFOV
    elseif Config.CustomFOVEnabled then
        Camera.FieldOfView = Config.CustomFOVValue
    end
end

Camera:GetPropertyChangedSignal("FieldOfView"):Connect(updateFOV)

local function CreateRubikBoldLabel(parent, size)
    local label = Instance.new("TextLabel")
    label.Parent = parent
    label.BackgroundTransparency = 1
    label.FontFace = Font.new("rbxasset://fonts/families/Rubik.json", Enum.FontWeight.Bold, Enum.FontStyle.Normal)
    label.TextSize = size or 13
    label.TextColor3 = Color3.new(1,1,1)
    label.TextStrokeTransparency = 0
    label.TextStrokeColor3 = Color3.new(0,0,0)
    label.RichText = true
    label.TextXAlignment = Enum.TextXAlignment.Center
    label.Size = UDim2.new(0, 200, 0, 15)
    label.Visible = false
    return label
end

-- Introduction + Tabs
task.spawn(function()
    library:BeginIntroduction()
    library:AddIntroductionMessage("Loading Syperium...")
    task.wait(0.7)
    library:AddIntroductionMessage("Bypassing...")
    task.wait(0.7)
    library:AddIntroductionMessage("Applying Optimizations...")
    task.wait(0.7)
    library:AddIntroductionMessage("Welcome, " .. LocalPlayer.Name)
    task.wait(0.7)
    library:EndIntroduction()
   
    task.wait(0.1)
    VirtualInputManager:SendKeyEvent(true, MainKeybind, false, game)
    VirtualInputManager:SendKeyEvent(false, MainKeybind, false, game)
   
    local Combat = library:NewTab("COMBAT")
    local Visuals = library:NewTab("ESP")
    local Misc = library:NewTab("MISC")
   
    Combat:NewSection("Aimbot")
    Combat:NewToggle("Enable Aimbot", false, function(v) Config.AimbotEnabled = v; ForceUpdateKeybindHUD() end)
    Combat:NewKeybind("Aimbot Keybind", Config.AimbotKey, function(k) Config.AimbotKey = k; ForceUpdateKeybindHUD() end)
    Combat:NewSlider("Smoothing Amount", "", false, "", {min=1,max=50,default=5}, function(v) Config.AimSmoothing = v end)
    Combat:NewToggle("FOV Circle", false, function(v) Config.AimFOVEnabled = v end)
    Combat:NewSlider("FOV Radius", "", false, "", {min=30,max=1000,default=100}, function(v) Config.AimFOVSize = v end)
   
    Combat:NewSection("Exploits")
    Combat:NewToggle("Hitbox Expander", false, function(v) Config.HitboxExpander = v end)
    Combat:NewSlider("Hitbox Size", "", false, "", {min=2,max=50,default=15}, function(v) Config.HitboxSize = v end)
   
    Visuals:NewSection("Player ESP")
    Visuals:NewToggle("Player ESP", false, function(v) Config.PlayerESP = v end)
    Visuals:NewToggle("Box", false, function(v) Config.BoxESP = v end)
    Visuals:NewToggle("Name", false, function(v) Config.NameESP = v end)
    Visuals:NewToggle("Status", false, function(v) Config.StatusESP = v end)
    Visuals:NewToggle("HealthBar", false, function(v) Config.HealthBar = v end)
    Visuals:NewToggle("Weapon", false, function(v) Config.ToolESP = v end)
    Visuals:NewToggle("Distance", false, function(v) Config.DistanceESP = v end)
    Visuals:NewSlider("Render Distance", "", false, "", {min=100,max=5000,default=2000}, function(v) Config.RenderDistance = v end)
   
    Visuals:NewSection("Crate Visuals")
    Visuals:NewToggle("Crate ESP", false, function(v) Config.CrateESP = v end)
    Visuals:NewToggle("Glow (Rarity Color)", false, function(v) Config.CrateHighlight = v end)
   
    Visuals:NewSection("Crate Rarity Filter")
    local RarityNames = {"Common","Uncommon","Rare","Epic","Legendary","Mythic"}
    for i, name in ipairs(RarityNames) do
        Visuals:NewToggle("Include "..name, true, function(v)
            Config.CrateRarities[tostring(i)] = v
        end)
    end
   
    Misc:NewSection("Keybind List")
    Misc:NewToggle("Enable Keybind List", true, function(v)
        Config.KeybindListEnabled = v
        KeybindHUD:Enable(v)
        ForceUpdateKeybindHUD()
    end)
   
    Misc:NewSection("Camera & Zoom")
    Misc:NewToggle("Enable Custom FOV", false, function(v) Config.CustomFOVEnabled = v updateFOV() end)
    Misc:NewSlider("Field of View", "", false, "", {min=30,max=120,default=70}, function(v) Config.CustomFOVValue = v updateFOV() end)
    Misc:NewToggle("Enable Zoom", false, function(v) Config.ZoomEnabled = v; ForceUpdateKeybindHUD() end)
    Misc:NewKeybind("Zoom Keybind", Config.ZoomKey, function(k) Config.ZoomKey = k; ForceUpdateKeybindHUD() end)
    Misc:NewSlider("Zoom FOV Amount", "", false, "", {min=5,max=50,default=30}, function(v) Config.ZoomFOV = v end)
   
    Misc:NewSection("Movement")
    Misc:NewToggle("Enable Speed", false, function(v)
        Config.WalkSpeedEnabled = v
        if not v then Config.WalkSpeedActive = false end
        ForceUpdateKeybindHUD()
    end)
    Misc:NewKeybind("Speed Keybind", Config.WalkSpeedKey, function(k) Config.WalkSpeedKey = k; ForceUpdateKeybindHUD() end)
    Misc:NewSlider("WalkSpeed Value", "", false, "", {min=16,max=250,default=16}, function(v) Config.WalkSpeedValue = v end)
   
    Misc:NewSection("Aura Farm")
    Misc:NewToggle("Aura Farm", false, function(v) Config.AutoFarm = v end)
   
    Misc:NewSection("Optimization")
    Misc:NewButton("POTATO MODE (Safe Optimize)", function()
        task.spawn(function()
            Lighting.GlobalShadows = false
            Lighting.FogEnd = 9e9
            for _, v in pairs(Lighting:GetChildren()) do
                if v:IsA("PostEffect") or v:IsA("BloomEffect") or v:IsA("BlurEffect") then
                    v.Enabled = false
                end
            end
            for i, v in ipairs(Workspace:GetDescendants()) do
                if i % 150 == 0 then task.wait() end
                if v:IsA("BasePart") then
                    v.Material = Enum.Material.SmoothPlastic
                    v.CastShadow = false
                elseif v:IsA("Texture") or v:IsA("Decal") then
                    v:Destroy()
                elseif v:IsA("ParticleEmitter") or v:IsA("Explosion") then
                    v.Enabled = false
                end
            end
        end)
    end)
   
    Misc:NewButton("REJOIN SERVER", function()
        TeleportService:TeleportToPlaceInstance(game.PlaceId, game.JobId, LocalPlayer)
    end)

    -- Initial update
    task.wait(0.5)
    ForceUpdateKeybindHUD()
end)

--------------------------------------------------------------------------------
-- PHYSICS & MOVEMENT
--------------------------------------------------------------------------------
UserInputService.InputBegan:Connect(function(input, gameProcessed)
    if gameProcessed then return end
    if input.KeyCode == Config.WalkSpeedKey and Config.WalkSpeedEnabled then
        Config.WalkSpeedActive = not Config.WalkSpeedActive
    end
    if input.KeyCode == Config.ZoomKey and Config.ZoomEnabled then
        Config.IsZooming = true
        updateFOV()
    end
end)

UserInputService.InputEnded:Connect(function(input)
    if input.KeyCode == Config.ZoomKey then
        Config.IsZooming = false
        updateFOV()
    end
end)

RunService.Stepped:Connect(function()
    local char = LocalPlayer.Character
    if not char then return end
    local hum = char:FindFirstChildOfClass("Humanoid")
    local hrp = char:FindFirstChild("HumanoidRootPart")
   
    if hrp and hum and Config.WalkSpeedEnabled and Config.WalkSpeedActive then
        local moveDir = hum.MoveDirection
        if moveDir.Magnitude > 0 then
            hrp.AssemblyLinearVelocity = Vector3.new(
                moveDir.X * Config.WalkSpeedValue,
                hrp.AssemblyLinearVelocity.Y,
                moveDir.Z * Config.WalkSpeedValue
            )
        end
    end

    -- Hitbox Expander
    for _, p in pairs(Players:GetPlayers()) do
        if p ~= LocalPlayer and p.Character and p.Character:FindFirstChild("Head") then
            local head = p.Character.Head
            if Config.HitboxExpander then
                head.Size = Vector3.new(Config.HitboxSize, Config.HitboxSize, Config.HitboxSize)
                head.Transparency = Config.HitboxTransparency
                head.CanCollide = false
                head.Massless = true
            else
                head.Size = Vector3.new(2, 1, 1)
                head.Transparency = 0
                head.CanCollide = true
                head.Massless = false
            end
        end
    end
end)

--------------------------------------------------------------------------------
-- MAIN ENGINE (Aimbot, ESP, etc.)
--------------------------------------------------------------------------------
local FOVCircle = Drawing.new("Circle")
FOVCircle.Thickness = 1
FOVCircle.NumSides = 100
FOVCircle.Color = Color3.new(1,1,1)
FOVCircle.Visible = false

local Watermark = library:Watermark("Syperium | Optimized")
local FPSCounter = library:Watermark("FPS: 0")

RunService.RenderStepped:Connect(function(dt)
    FPSCounter:SetText("FPS: " .. math.round(1/dt))
    local ping = Stats.Network.ServerStatsItem["Data Ping"]:GetValueString()
    Watermark:SetText("Syperium Private | Ping: " .. ping)
   
    FOVCircle.Visible = Config.AimFOVEnabled
    FOVCircle.Position = UserInputService:GetMouseLocation()
    FOVCircle.Radius = Config.AimFOVSize

    if Config.AimbotEnabled and UserInputService:IsKeyDown(Config.AimbotKey) then
        local target = GetClosestPlayer() -- (Add your GetClosestPlayer function here)
        if target and target.Character then
            local aimPart = target.Character:FindFirstChild(Config.AimPart or "Head")
            if aimPart then
                local targetCFrame = CFrame.new(Camera.CFrame.Position, aimPart.Position)
                local alpha = 1 / math.max(Config.AimSmoothing, 1)
                Camera.CFrame = Camera.CFrame:Lerp(targetCFrame, alpha)
            end
        end
    end

    -- Add your full ESP + Crate logic here
end)

-- AutoFarm (add your code here)
task.spawn(function()
    while true do
        task.wait(0.7)
        if not Config.AutoFarm then continue end
        -- your autofarm code
    end
end)

--------------------------------------------------------------------------------
-- BOOT
--------------------------------------------------------------------------------
local function Register(obj)
    if obj:IsA("Model") and obj.Name == "CratePrefab" then
        local gui = Instance.new("ScreenGui", CoreGui)
        gui.IgnoreGuiInset = true
        -- your crate esp logic
    end
end

Workspace.DescendantAdded:Connect(Register)
for _, v in pairs(Workspace:GetDescendants()) do Register(v) end

print("Syperium Loaded Successfully")
