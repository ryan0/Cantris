--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/7/2016
-- Time: 9:35 PM
-- To change this template use File | Settings | File Templates.
--

local wolfControl = {}
wolfControl.__index = wolfControl

local States = {
    patrol = 0,
    chase = 1
}

function wolfControl.new()
    local self = setmetatable({}, wolfControl)
    self.state = States.patrol
    self.patrolTime = 4
    self.patrolVel = 8
    self.increment = false
    self.timer = self.patrolTime
    return self
end

function wolfControl:start(entity, scene)
    self.playerRef = getEntityById(scene, "Player")
    print("wolfControl.lua Started")
end

function wolfControl:update(tpf, entity, scene)
    if self.state == States.patrol then
        self:patrol(tpf, entity)
    elseif self.state == States.chase then
        self:chase(entity)
    end

    local xVel = math.abs(getVelocity(entity):x())
    if xVel < .5 then setCurrentAnimation(entity, "Standing")
    elseif xVel < 10 then setCurrentAnimation(entity, "Walking")
    else setCurrentAnimation(entity, "Running") end
end

function wolfControl:finish(entity)


end


function wolfControl:chase(entity)
    local force = Vector:new()
    local direction = Vector:new()  direction:set_y(1)
    local xPos = getPosition(entity):x()
    local playerPos = getPosition(self.playerRef):x()
    if playerPos > xPos then
        force:set_x(200);
        applyForceToCenter(entity, force, true)
        direction:set_x(1)
        setScale(entity, direction)
    elseif playerPos < xPos then
        force:set_x(-200);
        applyForceToCenter(entity, force, true)
        direction:set_x(-1)
        setScale(entity, direction)
    end
end

function wolfControl:patrol(tpf, entity)
    local xVel = math.abs(getVelocity(entity):x())
    if self.timer < -self.patrolTime then
        self.increment = true
    elseif self.timer > self.patrolTime then
        self.increment = false
    end

    if self.increment then self.timer = self.timer + tpf
    else self.timer = self.timer - tpf end

    local force = Vector:new()
    local direction = Vector:new()  direction:set_y(1)

    if self.timer > 2 and xVel < self.patrolVel then
        force:set_x(100);
        applyForceToCenter(entity, force, true)
        direction:set_x(1)
        setScale(entity, direction)
    elseif self.timer < -2 and xVel < self.patrolVel then
        force:set_x(-100);
        applyForceToCenter(entity, force, true)
        direction:set_x(-1)
        setScale(entity, direction)
    end

    local xPos = getPosition(entity):x()
    local playerPos = getPosition(self.playerRef):x()
    if xPos - playerPos < 15 then
        self.state = States.chase
    end
end

return wolfControl

