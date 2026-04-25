--// Integrated Syperium Key System (Depso Aesthetic)
local CorrectKey = "XvR0zLp88Wq22nNbBvVmMpPqQwWeErRtTyY"
local KeyLink = "https://discord.gg/syperium" 
local KeyVerified = false

--// Services & References
local Services = setmetatable({}, {
    __index = function(self, Name: string)
        return game:GetService(Name)
    end,
})
local TweenService    = Services.TweenService
local Players         = Services.Players
local RunService      = Services.RunService
local Workspace       = Services.Workspace
local UserInputService = Services.UserInputService
local Stats           = Services.Stats
local Lighting        = Services.Lighting
local TeleportService = game:GetService("TeleportService")
local ContextActionService = game:GetService("ContextActionService")
local VirtualInputManager = game:GetService("VirtualInputManager")
local CoreGui = game:GetService("Players").LocalPlayer:WaitForChild("PlayerGui"):FindFirstChild("CustomChat") or game:GetService("CoreGui")
local LocalPlayer = Players.LocalPlayer
local Camera = Workspace.CurrentCamera

local library_colors = {
    backgroundColor = Color3.fromRGB(31, 31, 31),
    acientColor     = Color3.fromRGB(10,30,61),
    companyColor    = Color3.fromRGB(163, 151, 255),
    lightGray       = Color3.fromRGB(48, 48, 48),
    Font            = Enum.Font.Code,
    rainbowColors   = ColorSequence.new{
        ColorSequenceKeypoint.new(0.00, Color3.fromRGB(241, 137, 53)), 
        ColorSequenceKeypoint.new(0.33, Color3.fromRGB(241, 53, 106)), 
        ColorSequenceKeypoint.new(0.66, Color3.fromRGB(133, 53, 241)), 
        ColorSequenceKeypoint.new(1,    Color3.fromRGB(53, 186, 241))
    }
}

--// Clipboard Utility
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
    layout.SortOrder = Enum.SortOrder.LayoutOrder
    
    local submit = Instance.new("TextButton", buttonContainer)
    submit.Name = "Submit"
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
    getKey.Name = "GetKey"
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
    
    repeat task.wait() until KeyVerified == true
end

-- Start Key System
LaunchKeySystem()

--------------------------------------------------------------------------------
-- SYPERIUM ULTIMATE | CORE
--------------------------------------------------------------------------------

local library = loadstring(game:HttpGet("https://raw.githubusercontent.com/L3nzo/SyperiumFree/refs/heads/main/SyperiumUiLib"))()
library.headerColor  = Color3.fromRGB(51, 158, 190)
library.companyColor = Color3.fromRGB(163, 151, 255)
library.acientColor  = Color3.fromRGB(159, 115, 255)

local MainKeybind = Enum.KeyCode.RightShift

ContextActionService:BindActionAtPriority("SyperiumIntroLock", function()
    return Enum.ContextActionResult.Sink
end, false, 2000, MainKeybind)

library:Init({
    version = "Syperium | Private",
    title   = "Private",
    company = "Syperium",
    keybind = MainKeybind,
    BlurEffect = true
})

local Config = {
    AimbotEnabled    = false,
    AimbotKey        = Enum.KeyCode.E, 
    AimPart          = "Head",
    AimSmoothing     = 5,
    AimFOVEnabled    = false,
    AimFOVSize       = 100,
    HitboxExpander   = false,
    HitboxSize       = 15,
    HitboxTransparency = 0.5,
    PlayerESP        = false,
    BoxESP           = false,
    NameESP          = false,
    DistanceESP      = false,
    ToolESP          = false,
    HealthBar        = false,
    StatusESP        = false,
    RenderDistance   = 2000,
    CrateESP         = false,
    CrateName        = true,
    CrateHighlight   = false,
    CrateRarities    = {["1"]=true,["2"]=true,["3"]=true,["4"]=true,["5"]=true,["6"]=true},
    AutoFarm         = false,
    WalkSpeedEnabled = false,
    WalkSpeedActive  = false,
    WalkSpeedValue   = 16,
    WalkSpeedKey     = Enum.KeyCode.X,
    ZoomEnabled      = false,
    ZoomKey          = Enum.KeyCode.V,
    ZoomFOV          = 30,
    CustomFOVEnabled = false,
    CustomFOVValue   = 70,
    IsZooming        = false,
    KeybindListEnabled = true
}

-- [[ KEYBIND HUD UI - REDESIGNED & DRAGGABLE ]] --
local HudContainer = Instance.new("ScreenGui", CoreGui)
HudContainer.Name = "SyperiumKeybindHUD"

local HudFrame = Instance.new("Frame", HudContainer)
HudFrame.Size = UDim2.new(0, 180, 0, 25) 
HudFrame.Position = UDim2.new(0, 100, 0.5, -40)   -- ← CENTER LEFT POSITION
HudFrame.BackgroundColor3 = Color3.fromRGB(12, 12, 12)
HudFrame.BorderSizePixel = 0
HudFrame.Active = true
HudFrame.ClipsDescendants = true
HudFrame.Visible = Config.KeybindListEnabled

-- Dragging Logic
local dragging, dragInput, dragStart, startPos
HudFrame.InputBegan:Connect(function(input)
    if input.UserInputType == Enum.UserInputType.MouseButton1 then
        dragging = true
        dragStart = input.Position
        startPos = HudFrame.Position
        input.Changed:Connect(function()
            if input.UserInputState == Enum.UserInputState.End then dragging = false end
        end)
    end
end)

HudFrame.InputChanged:Connect(function(input)
    if input.UserInputType == Enum.UserInputType.MouseMovement then dragInput = input end
end)

UserInputService.InputChanged:Connect(function(input)
    if input == dragInput and dragging then
        local delta = input.Position - dragStart
        HudFrame.Position = UDim2.new(startPos.X.Scale, startPos.X.Offset + delta.X, startPos.Y.Scale, startPos.Y.Offset + delta.Y)
    end
end)

-- Aesthetic: Rainbow Bar
local HudBar = Instance.new("Frame", HudFrame)
HudBar.Size = UDim2.new(1, 0, 0, 2)
HudBar.BorderSizePixel = 0
HudBar.ZIndex = 2

local HudBarGradient = Instance.new("UIGradient", HudBar)
HudBarGradient.Color = library_colors.rainbowColors

task.spawn(function()
    while true do
        HudBarGradient.Offset = Vector2.new(-1, 0)
        local t = TweenService:Create(HudBarGradient, TweenInfo.new(3, Enum.EasingStyle.Linear), {Offset = Vector2.new(1, 0)})
        t:Play()
        t.Completed:Wait()
    end
end)

-- Title
local HudTitle = Instance.new("TextLabel", HudFrame)
HudTitle.Size = UDim2.new(1, 0, 0, 22)
HudTitle.Position = UDim2.new(0, 0, 0, 2)
HudTitle.BackgroundTransparency = 1
HudTitle.Font = Enum.Font.SourceSansBold
HudTitle.Text = "Keybinds"
HudTitle.TextColor3 = Color3.fromRGB(255, 255, 255)
HudTitle.TextSize = 14

local Separator = Instance.new("Frame", HudFrame)
Separator.Size = UDim2.new(1, -10, 0, 1)
Separator.Position = UDim2.new(0, 5, 0, 24)
Separator.BackgroundColor3 = Color3.fromRGB(35, 35, 35)
Separator.BorderSizePixel = 0

-- Keybind List Container
local HudList = Instance.new("TextLabel", HudFrame)
HudList.Size = UDim2.new(1, -12, 1, -28)
HudList.Position = UDim2.new(0, 8, 0, 28)
HudList.BackgroundTransparency = 1
HudList.Font = Enum.Font.SourceSans
HudList.TextColor3 = Color3.fromRGB(210, 210, 210)
HudList.TextSize = 13
HudList.TextXAlignment = Enum.TextXAlignment.Left
HudList.TextYAlignment = Enum.TextYAlignment.Top
HudList.RichText = true

local function UpdateHUD()
    HudFrame.Visible = Config.KeybindListEnabled
    if not Config.KeybindListEnabled then return end
    
    local lines = {}
    local function addBind(name, key, mode)
        if not key then return end
        local kName = (typeof(key) == "EnumItem") and key.Name or tostring(key)
        table.insert(lines, string.format(
            "<font color='rgb(100,100,100)'>[</font> %s <font color='rgb(100,100,100)'>]</font> %s - %s",
            mode, name, kName
        ))
    end
    
    if Config.AimbotEnabled    then addBind("Aimbot",    Config.AimbotKey,    "Hold") end
    if Config.WalkSpeedEnabled then addBind("Speed key", Config.WalkSpeedKey, "Hold") end
    if Config.ZoomEnabled      then addBind("Zoom",      Config.ZoomKey,      "Hold") end
    addBind("Menu", MainKeybind, "Toggle")
    
    HudList.Text = table.concat(lines, "\n")
    
    local targetHeight = #lines > 0 and (35 + (#lines * 16)) or 25
    TweenService:Create(HudFrame, TweenInfo.new(0.2), {Size = UDim2.new(0, 180, 0, targetHeight)}):Play()
end

RunService.RenderStepped:Connect(UpdateHUD)

local RarityData = {
    ["1"] = {Name = "Common",    Color = Color3.fromRGB(170,170,170)},
    ["2"] = {Name = "Uncommon",  Color = Color3.fromRGB( 85,255,127)},
    ["3"] = {Name = "Rare",      Color = Color3.fromRGB( 85,170,255)},
    ["4"] = {Name = "Epic",      Color = Color3.fromRGB(170, 85,255)},
    ["5"] = {Name = "Legendary", Color = Color3.fromRGB(255,255,  0)},
    ["6"] = {Name = "Mythic",    Color = Color3.fromRGB(255,  0,  0)}
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

-- Introduction Sequence + Tabs
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
    Combat:NewToggle("Enable Aimbot", false, function(v) Config.AimbotEnabled = v end)
    Combat:NewKeybind("Aimbot Keybind", Config.AimbotKey, function(k) Config.AimbotKey = k end)
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
    Misc:NewToggle("KeybindList", true, function(v) Config.KeybindListEnabled = v end)
    
    Misc:NewSection("Camera & Zoom")
    Misc:NewToggle("Enable Custom FOV", false, function(v) Config.CustomFOVEnabled = v updateFOV() end)
    Misc:NewSlider("Field of View", "", false, "", {min=30,max=120,default=70}, function(v) Config.CustomFOVValue = v updateFOV() end)
    Misc:NewToggle("Enable Zoom", false, function(v) Config.ZoomEnabled = v end)
    Misc:NewKeybind("Zoom Keybind", Config.ZoomKey, function(k) Config.ZoomKey = k end)
    Misc:NewSlider("Zoom FOV Amount", "", false, "", {min=5,max=50,default=30}, function(v) Config.ZoomFOV = v end)
    
    Misc:NewSection("Movement")
    Misc:NewToggle("Enable Speed", false, function(v) 
        Config.WalkSpeedEnabled = v 
        if not v then Config.WalkSpeedActive = false end
    end)
    Misc:NewKeybind("Speed Keybind", Config.WalkSpeedKey, function(k) Config.WalkSpeedKey = k end)
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
end)

--------------------------------------------------------------------------------
-- [[ PHYSICS & MOVEMENT ]] --
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
    
    if hrp and hum then
        if Config.WalkSpeedEnabled and Config.WalkSpeedActive then
            local moveDir = hum.MoveDirection
            if moveDir.Magnitude > 0 then
                hrp.AssemblyLinearVelocity = Vector3.new(
                    moveDir.X * Config.WalkSpeedValue,
                    hrp.AssemblyLinearVelocity.Y,
                    moveDir.Z * Config.WalkSpeedValue
                )
            end
        end
    end
    
    local targetSize = Vector3.new(Config.HitboxSize, Config.HitboxSize, Config.HitboxSize)
    local defaultSize = Vector3.new(2, 1, 1)
    
    for _, p in pairs(Players:GetPlayers()) do
        if p ~= LocalPlayer and p.Character and p.Character:FindFirstChild("Head") then
            local head = p.Character.Head
            if Config.HitboxExpander then
                head.Size = targetSize
                head.Transparency = Config.HitboxTransparency
                head.CanCollide = false
                head.Massless = true
            else
                if head.Size ~= defaultSize then
                    head.Size = defaultSize
                    head.Transparency = 0
                    head.CanCollide = true
                    head.Massless = false
                end
            end
        end
    end
end)

--------------------------------------------------------------------------------
-- [[ MAIN ENGINE ]] --
--------------------------------------------------------------------------------

local PlayerESPTable = {}
local CrateTable = {}
local ESPContainer = Instance.new("Folder", CoreGui)
ESPContainer.Name = "Syperium_Geometric_Assets"

local function IsValid(p)
    if not p or not p.Character then return false end
    local hrp = p.Character:FindFirstChild("HumanoidRootPart")
    local hum = p.Character:FindFirstChildOfClass("Humanoid")
    return hrp and hum and hum.Health > 0
end

local function GetClosestPlayer()
    local target, dist = nil, (Config.AimFOVEnabled and Config.AimFOVSize or math.huge)
    local mousePos = UserInputService:GetMouseLocation()
    for _, v in pairs(Players:GetPlayers()) do
        if v == LocalPlayer then continue end
        local char = v.Character
        if not char then continue end
        
        local aimPart = char:FindFirstChild(Config.AimPart or "Head")
        if not aimPart or not aimPart:IsA("BasePart") then continue end
        
        local pos, onScreen = Camera:WorldToViewportPoint(aimPart.Position)
        if not onScreen then continue end
        
        local mag = (Vector2.new(pos.X, pos.Y) - mousePos).Magnitude
        if mag < dist then
            dist = mag
            target = v
        end
    end
    return target
end

local function CreateESP(p)
    if PlayerESPTable[p] then return end
    local gui = Instance.new("ScreenGui", ESPContainer)
    gui.Name = p.UserId .. "_ESP"
    gui.IgnoreGuiInset = true
    
    local elements = {
        BoxOutline   = Drawing.new("Square"),
        Box          = Drawing.new("Square"),
        Name         = CreateRubikBoldLabel(gui, 14),
        Dist         = CreateRubikBoldLabel(gui, 12),
        Tool         = CreateRubikBoldLabel(gui, 12),
        Status       = CreateRubikBoldLabel(gui, 12),
        HealthOutline = Drawing.new("Square"),
        HealthBar    = Drawing.new("Square"),
    }
    
    elements.BoxOutline.Thickness = 5
    elements.BoxOutline.Color = Color3.new(0,0,0)
    elements.BoxOutline.Transparency = 0.8
    elements.BoxOutline.Filled = false
    
    elements.Box.Thickness = 1.5
    elements.Box.Color = Color3.new(1,1,1)
    elements.Box.Filled = false
    
    elements.HealthOutline.Thickness = 1
    elements.HealthOutline.Color = Color3.new(0,0,0)
    elements.HealthOutline.Transparency = 0
    elements.HealthOutline.Filled = true
    
    elements.HealthBar.Thickness = 1
    elements.HealthBar.Filled = true
    
    elements.Status.TextXAlignment = Enum.TextXAlignment.Left
    
    PlayerESPTable[p] = { Elements = elements, Container = gui }
end

local function CleanESP(p)
    if PlayerESPTable[p] then
        local data = PlayerESPTable[p]
        pcall(function()
            for _, v in pairs(data.Elements) do 
                if typeof(v) == "Drawing" then v:Remove() else v:Destroy() end 
            end
            data.Container:Destroy()
        end)
        PlayerESPTable[p] = nil
    end
end

local FOVCircle = Drawing.new("Circle")
FOVCircle.Thickness = 1
FOVCircle.NumSides = 100
FOVCircle.Color = Color3.new(1,1,1)
FOVCircle.Visible = false

local Watermark = library:Watermark("Syperium | Optimized")
local FPSCounter = library:Watermark("FPS: 0")

RunService.RenderStepped:Connect(function(dt)
    UpdateHUD()
    FPSCounter:SetText("FPS: " .. math.round(1/dt))
    local ping = Stats.Network.ServerStatsItem["Data Ping"]:GetValueString()
    Watermark:SetText("Syperium Private | Ping: " .. ping)
    
    FOVCircle.Visible = Config.AimFOVEnabled
    FOVCircle.Position = UserInputService:GetMouseLocation()
    FOVCircle.Radius = Config.AimFOVSize
    
    if Config.AimbotEnabled and UserInputService:IsKeyDown(Config.AimbotKey) then
        local target = GetClosestPlayer()
        if target and target.Character then
            local aimPart = target.Character:FindFirstChild(Config.AimPart or "Head")
            if aimPart and aimPart:IsA("BasePart") then
                local aimPos = aimPart.Position
                local targetCFrame = CFrame.new(Camera.CFrame.Position, aimPos)
                local alpha = 1 / math.max(Config.AimSmoothing, 1)
                Camera.CFrame = Camera.CFrame:Lerp(targetCFrame, alpha)
            end
        end
    end
    
    -- PLAYER ESP LOOP
    for _, p in pairs(Players:GetPlayers()) do
        if p == LocalPlayer then continue end
        if IsValid(p) and Config.PlayerESP then
            CreateESP(p)
            local esp = PlayerESPTable[p].Elements
            local hrp, head, hum = p.Character.HumanoidRootPart, p.Character.Head, p.Character.Humanoid
            local pos, vis = Camera:WorldToViewportPoint(hrp.Position)
            local dist = (Camera.CFrame.Position - hrp.Position).Magnitude
            
            if vis and dist <= Config.RenderDistance then
                local tPos = Camera:WorldToViewportPoint(head.Position + Vector3.new(0, 0.6, 0))
                local bPos = Camera:WorldToViewportPoint(hrp.Position - Vector3.new(0, 3, 0))
                local h, w = math.abs(tPos.Y - bPos.Y), math.abs(tPos.Y - bPos.Y) / 1.6
                local x, y = pos.X - w/2, pos.Y - h/2
                
                esp.Box.Visible = Config.BoxESP; esp.Box.Size = Vector2.new(w, h); esp.Box.Position = Vector2.new(x, y)
                esp.BoxOutline.Visible = Config.BoxESP; esp.BoxOutline.Size = esp.Box.Size; esp.BoxOutline.Position = esp.Box.Position
                esp.Name.Visible = Config.NameESP; esp.Name.Text = "<b>" .. p.Name .. "</b>"; esp.Name.Position = UDim2.new(0, pos.X - 100, 0, y - 18)
                esp.Status.Visible = Config.StatusESP
                esp.Status.Text = "<b>" .. (hum.MoveDirection.Magnitude > 0 and "Running" or "Idle") .. "</b>"
                esp.Status.Position = UDim2.new(0, x + w + 5, 0, y)
                
                if Config.ToolESP then
                    local tool = p.Character:FindFirstChildOfClass("Tool")
                    esp.Tool.Visible = true; esp.Tool.Text = "<b>" .. (tool and tool.Name or "None") .. "</b>"; esp.Tool.Position = UDim2.new(0, pos.X - 100, 0, y + h + 8)
                else esp.Tool.Visible = false end
                
                if Config.DistanceESP then
                    esp.Dist.Visible = true; esp.Dist.Text = "<b>" .. math.floor(dist) .. "m</b>"; esp.Dist.Position = UDim2.new(0, pos.X - 100, 0, y + h + (Config.ToolESP and 22 or 8))
                else esp.Dist.Visible = false end
                
                if Config.HealthBar then
                    local hpPct = math.clamp(hum.Health / hum.MaxHealth, 0, 1)
                    esp.HealthOutline.Visible, esp.HealthBar.Visible = true, true
                    esp.HealthOutline.Position, esp.HealthOutline.Size = Vector2.new(x, y + h + 2), Vector2.new(w, 4)
                    esp.HealthBar.Position, esp.HealthBar.Size = esp.HealthOutline.Position, Vector2.new(w * hpPct, 4)
                    esp.HealthBar.Color = Color3.fromRGB(255, 0, 0):Lerp(Color3.fromRGB(0, 255, 0), hpPct)
                else esp.HealthBar.Visible, esp.HealthOutline.Visible = false, false end
            else
                for _, obj in pairs(esp) do pcall(function() obj.Visible = false end) end
            end
        elseif PlayerESPTable[p] then
            for _, obj in pairs(PlayerESPTable[p].Elements) do pcall(function() obj.Visible = false end) end
        end
    end
    
    -- Crate ESP
    if Config.CrateESP then
        for model, data in pairs(CrateTable) do
            pcall(function()
                if model and model.Parent then
                    local rar = tostring(model:GetAttribute("Rarity") or "1")
                    local info = RarityData[rar] or {Name = "Unknown", Color = Color3.new(1,1,1)}
                    
                    local prim = model.PrimaryPart or model:FindFirstChildWhichIsA("BasePart", true)
                    if prim and Config.CrateRarities[rar] then
                        local p, vis = Camera:WorldToViewportPoint(prim.Position)
                        if vis then
                            data.Label.Visible = Config.CrateName
                            data.Label.Text = "<b>["..info.Name.."] Crate</b>"
                            data.Label.Position = UDim2.new(0, p.X - 100, 0, p.Y)
                            data.Label.TextColor3 = info.Color
                            
                            local hl = model:FindFirstChild("Syperium_Crate_HL")
                            if Config.CrateHighlight then
                                if not hl then 
                                    hl = Instance.new("Highlight", model)
                                    hl.Name = "Syperium_Crate_HL"
                                    hl.FillTransparency = 1 
                                end
                                hl.Enabled = true
                                hl.OutlineColor = info.Color
                            elseif hl then 
                                hl.Enabled = false 
                            end
                        else 
                            data.Label.Visible = false 
                        end
                    else 
                        data.Label.Visible = false 
                    end
                end
            end)
        end
    else
        for model, data in pairs(CrateTable) do
            pcall(function()
                data.Label.Visible = false
                local hl = model:FindFirstChild("Syperium_Crate_HL")
                if hl then hl.Enabled = false end
            end)
        end
    end
end)

-- AutoFarm
task.spawn(function()
    while true do
        task.wait(0.7)
        if not Config.AutoFarm then continue end
        if not (LocalPlayer.Character and LocalPlayer.Character:FindFirstChild("HumanoidRootPart")) then continue end
        
        for model, _ in pairs(CrateTable) do
            if not Config.AutoFarm then break end
            pcall(function()
                if model and model.Parent then
                    local r = tostring(model:GetAttribute("Rarity") or "1")
                    if Config.CrateRarities[r] then
                        local hrp = LocalPlayer.Character.HumanoidRootPart
                        local t = model.PrimaryPart or model:FindFirstChildWhichIsA("BasePart", true)
                        if t and hrp then
                            hrp.CFrame = t.CFrame + Vector3.new(0, 4, 0)
                            task.wait(0.15)
                            local prompt = model:FindFirstChildWhichIsA("ProximityPrompt", true)
                            if prompt then fireproximityprompt(prompt) end
                        end
                    end
                end
            end)
        end
    end
end)

--------------------------------------------------------------------------------
-- [[ BOOT ]] --
--------------------------------------------------------------------------------

local function Register(obj)
    if obj:IsA("Model") and obj.Name == "CratePrefab" then
        local gui = Instance.new("ScreenGui", ESPContainer)
        gui.IgnoreGuiInset = true
        CrateTable[obj] = { Label = CreateRubikBoldLabel(gui, 14), Container = gui }
    end
end

Workspace.DescendantAdded:Connect(Register)
for _, v in pairs(Workspace:GetDescendants()) do Register(v) end
Players.PlayerRemoving:Connect(CleanESP)

print("Syperium Loaded Successfully")
