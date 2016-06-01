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
    self.enteringState = true

    self.prevVelY = 0
    self.jumpDelay = .25
    self.jumpPower = -100
    self.jumpInputTimer = 0

    self.runForce = 200
    self.stopForce = 200
    self.runVel = 12

    return self
end

function playerControl:start(entity, scene)
    print("playerControl.lua Started")
    setCurrentAnimation(entity, "Standing")
end

function playerControl:update(tpf, entity, scene)
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

function playerControl:setState(state)
    self.state = state
    self.enteringState = true
end

function playerControl:standing(entity)
    if self.enteringState then
        setCurrentAnimation(entity, "Standing")
        self.enteringState = false
    end


    if Keys.D and Keys.A then
        --do notin
    elseif Keys.A or Keys.D then
        self:setState(States.running)
    elseif Keys.W and self.jumpDelay <= 0 then
        self:setState(States.jumping)
    else
        local xVel = getVelocity(entity):x()
        local stopVec = Vector:new()
        local mod = 0
        if(math.abs(xVel) < 1) then
            mod = math.abs(xVel)
        end

        if(xVel > 0) then
            stopVec:set_x(-self.stopForce * mod)
            applyForceToCenter(entity, stopVec, true)
        elseif(xVel < 0) then
            stopVec:set_x(self.stopForce * mod)
            applyForceToCenter(entity, stopVec, true)
        end
    end
end

function playerControl:running(entity)
    local direction = Vector:new()  direction:set_y(1)
    local currVelx = math.abs(getVelocity(entity):x())
    local runForce = Vector:new()

    if self.enteringState then
        setCurrentAnimation(entity, "Running")
        self.enteringState = false
    end


    if Keys.D and Keys.A then
        if math.abs(getVelocity(entity):x()) < .5 then
            self:setState(States.standing)
        end
    elseif Keys.W and self.jumpDelay <= 0 then
        self:setState(States.jumping)
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
    else
        local xVel = getVelocity(entity):x()
        local stopVec = Vector:new()
        if(xVel > 0) then
            stopVec:set_x(-self.stopForce)
            applyForceToCenter(entity, stopVec, true)
        elseif(xVel < 0) then
            stopVec:set_x(self.stopForce)
            applyForceToCenter(entity, stopVec, true)
        end
    end
end

function playerControl:jumping(entity)
    local direction = Vector:new()  direction:set_y(1)
    local currVelY = getVelocity(entity):y()
    local jumpForce = Vector.new()

    if self.enteringState then
        setCurrentAnimation(entity, "Jumping")
        local jumpVel = Vector:new()
        jumpVel:set_y(self.jumpPower);
        self.prevVelY = -1
        applyLinearImpulse(entity, jumpVel, getLocalCenter(entity), true)
        self.enteringState = false
    end


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
            jumpForce:set_x(50);
            applyForceToCenter(entity, jumpForce, true)
            direction:set_x(1)
            setScale(entity, direction)
        end
        if Keys.A then
            jumpForce:set_x(-50);
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