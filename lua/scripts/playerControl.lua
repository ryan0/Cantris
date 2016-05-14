--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/6/2016
-- Time: 8:01 PM
-- To change this template use File | Settings | File Templates.
--

local playerControl = {}
playerControl.__index = playerControl

local States = {
    standing = 0,
    running = 1,
    jumping = 2
}

local Keys = {
    W = false,
    S = false,
    A = false,
    D = false
}

function playerControl.new()
    local self = setmetatable({}, playerControl)
    self.state = States.standing
    self.prevVelY = 0
    self.jumpDelay = .25
    self.jumpPower = -70
    self.runForce = 150
    self.runVel = 30
    return self
end

function playerControl:start(entity, scene)
    print("playerControl.lua Started")
    setCurrentAnimation(entity, "Standing")
end

function playerControl:update(tpf, entity, scene)
    local velocity = getVelocity(entity)
    self.jumpDelay = self.jumpDelay - tpf
    self:getInput()

    if self.state == States.standing then self:standing(entity)
    elseif self.state == States.running then self:running(entity)
    elseif self.state == States.jumping then self:jumping(entity)
    else
        print("wrong state bud")
    end
end

function playerControl:finish(entity)

end


function playerControl:standing(entity)
    if Keys.D and Keys.A then
    elseif Keys.A or Keys.D then
        self.state = States.running
        setCurrentAnimation(entity, "Running")
    elseif Keys.W and self.jumpDelay <= 0 then self.state = States.jumping
        setCurrentAnimation(entity, "Jumping")
        local jumpVel = Vector:new()
        jumpVel:set_y(self.jumpPower);
        self.prevVelY = getVelocity(entity):y()
        applyLinearImpulse(entity, jumpVel, getLocalCenter(entity), true)
    end
end

function playerControl:running(entity)
    local direction = Vector:new()  direction:set_y(1)
    local currVelx = math.abs(getVelocity(entity):x())
    local runForce = Vector:new()

    if Keys.D and Keys.A then
        if math.abs(getVelocity(entity):x()) < .5 then
            self.state = States.standing
            setCurrentAnimation(entity, "Standing")
        end
    elseif Keys.W and self.jumpDelay <= 0 then
        self.state = States.jumping
        setCurrentAnimation(entity, "Jumping")
        local jumpVel = Vector:new()
        jumpVel:set_y(self.jumpPower);
        self.prevVelY = getVelocity(entity):y()
        applyLinearImpulse(entity, jumpVel, getLocalCenter(entity), true)
    elseif Keys.D and currVelx < self.runVel then
        runForce:set_x(self.runForce);
        applyForceToCenter(entity, runForce, true)
        direction:set_x(1)
        setScale(entity, direction)
    elseif Keys.A and currVelx < self.runVel then
        runForce:set_x(-self.runForce);
        applyForceToCenter(entity, runForce, true)
        direction:set_x(-1)
        setScale(entity, direction)
    elseif math.abs(getVelocity(entity):x()) < .5 then
        self.state = States.standing
        setCurrentAnimation(entity, "Standing")
    end
end

function playerControl:jumping(entity)
    local direction = Vector:new()  direction:set_y(1)
    local currVelY = getVelocity(entity):y()
    local jumpForce = Vector.new()

    if currVelY < self.prevVelY + 0.1 and currVelY > self.prevVelY - 0.1 then
        self.jumpDelay = .25
        if math.abs(getVelocity(entity):x()) < .5 then
            self.state = States.standing
            setCurrentAnimation(entity, "Standing")
        else
            self.state = States.running
            setCurrentAnimation(entity, "Running")
        end
    else
        if Keys.D then
            jumpForce:set_x(20);
            applyForceToCenter(entity, jumpForce, true)
            direction:set_x(1)
            setScale(entity, direction)
        end
        if Keys.A then
            jumpForce:set_x(-20);
            applyForceToCenter(entity, jumpForce, true)
            direction:set_x(-1)
            setScale(entity, direction)
        end
    end

    self.prevVelY = currVelY
end


function playerControl:getInput()
    if isKeyPressed("W") then Keys.W = true else Keys.W = false end
    if isKeyPressed("A") then Keys.A = true else Keys.A = false end
    if isKeyPressed("S") then Keys.S = true else Keys.S = false end
    if isKeyPressed("D") then Keys.D = true else Keys.D = false end
end

return playerControl