--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/9/2016
-- Time: 10:55 PM
-- To change this template use File | Settings | File Templates.
--

local gate = {}
gate.__index = gate

local States = {
    active = 0,
    inactive = 1
}

local warpTimer = 0

function gate.new(target)
    local self = setmetatable({}, gate)
    self.playerRef = nil
    self.targetRef = nil
    self.state = States.inactive
    self.targetId = target
    return self
end

function gate:start(entity, scene)
    print("Portal.lua Started")
    self.playerRef = getEntityById(scene, "Player")
    self.targetRef = getEntityById(scene, self.targetId)


    setCurrentAnimation(entity, "Portal1Reverse")
    local aniRef = getCurrentAnimation(entity)
    setLooped(aniRef, false)
    stop(aniRef)

    setCurrentAnimation(entity, "Portal1")
    aniRef = getCurrentAnimation(entity)
    setLooped(aniRef, false)
    stop(aniRef)
end

function gate:update(tpf, entity, scene)
    local playerPos = getPosition(self.playerRef):x()
    local position = getPosition(entity):x() + 2
    local distance = math.abs(playerPos - position)
    warpTimer = warpTimer - tpf

    if self.state == States.inactive then
        self:inactive(entity, distance)
    else
        self:active(entity, distance)
    end
end

function gate:finish(entity)

end

function gate:active(entity, distance)
    local aniRef = getCurrentAnimation(entity)
    if distance > 3.1 then
        self.state = States.inactive
        setCurrentAnimation(entity, "Portal1Reverse")
        aniRef = getCurrentAnimation(entity)
        play(aniRef)
    else
        if not isPlaying(aniRef) then
            setCurrentAnimation(entity, "Portal1Reverse")
        end
    end

    if isKeyPressed("E") and warpTimer < 0 then
        warpTimer = 2
        local newPos = getPosition(self.targetRef)
        newPos:set_x(newPos:x()+2)
        newPos:set_y(newPos:y()+2.3)
        setPhysicalPosition(self.playerRef, newPos)
    end
end

function gate:inactive(entity, distance)
    local aniRef = getCurrentAnimation(entity)
    if distance < 3 and math.abs(getVelocity(self.playerRef):x()) < 5 then
        self.state = States.active
        setCurrentAnimation(entity, "Portal1")
        aniRef = getCurrentAnimation(entity)
        play(aniRef)
    else
        if not isPlaying(aniRef) then
            setCurrentAnimation(entity, "Portal1")
        end
    end
end

return gate

