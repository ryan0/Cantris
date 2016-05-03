Spatial = {
    position = {0, 0}
}

Physical = {
    b2BodyDef = {
        position = {46.6, 49},
        type = "b2_staticBody"
    },

    b2FixtureDef = {
        friction = .3,
        restitution = 0.0,
        b2PolygonShape = {
            setAsBox = {5.1, 20}
        }
    }
}